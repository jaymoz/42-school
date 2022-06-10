#include "../include/Server.hpp"

std::vector<std::string> split_args(std::string args) {
	std::vector<std::string> result;
	size_t pos = 0;
	size_t newPos = 0;
	unsigned long spaceSkip = args.length();

	while (args[spaceSkip] == ' ' && spaceSkip != 0) {
		spaceSkip--;
	}
	if (spaceSkip != 0) {
		args = args.substr(0, spaceSkip + 1);
	}

	for (int i = 0; newPos != std::string::npos; i++) {
		newPos = args.find(',', pos);
		if (newPos == std::string::npos)
			result.push_back(args.substr(pos));
		else
			result.push_back(args.substr(pos, newPos - pos));
		pos = newPos + 1;
	}
	return result;
}

void    Server::ft_authenticate()
{
    std::cout << "authenticating..." << std::endl;
}

void    Server::ft_join_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    if (args.size() != 1)
    {
        std::string msg = "Erro: JOIN #channelName\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::IncompleteDetails(client);    
    }
    std::vector<std::string>    channelsToJoin = split_args(args.at(0));
    std::vector<std::string>::iterator it;
    for (it = channelsToJoin.begin(); it != channelsToJoin.end(); it++)
    {
        Channel *new_channel = Server::ft_find_channel(*it);
        if (new_channel == nullptr)
        {
            new_channel = new Channel(*it);
            this->_channels.push_back(new_channel);
            client->ft_add_channel(new_channel);
            new_channel->ft_add_Client(client);
            new_channel->ft_add_operator(client);
        }
        else
        {
            if (!new_channel->ft_client_exist(client->ft_get_nickname()))
            {
                client->ft_add_channel(new_channel);
                new_channel->ft_add_Client(client);
            }
        }
        std::string msg1 = client->ft_get_nickname() + " JOINED " + new_channel->ft_get_channel() + "\n";
        new_channel->ft_send_message(msg1,"you joined " + new_channel->ft_get_channel() + "\n",client, 0);
        new_channel->ft_send_message(msg1,"you joined " + new_channel->ft_get_channel() + "\n",client, 1);
    }
}

void    Server::ft_nick_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_get_password())
    {
        std::string msg = "Enter password first\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::NoPasswordProvided(client);
    }
 
    if (args.empty())
    {
        std::string msg = "Kindly provide complete Nick details\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::IncompleteDetails(client);
    }

    for (size_t i = 0; i < this->_clients.size(); i++)
    {
        if (this->_clients[i]->ft_get_nickname() == args[0])
        {
            std::string msg = "This NickName already exists\n";
            send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
            std::string error = "\033[0;31mServer Error: Nickname already exists\033[0m";
            throw error;
        }
    }
    client->ft_set_nickname(args[0]);
    client->bool_has_nickname(true);
    std::string msg = "Successflly set Nickname to " + client->ft_get_nickname() + "\n";
    if (client->ft_check_if_nickname() && client->ft_check_if_username())
    {
        client->ft_set_registered(true);
        std::cout << "User @" + client->ft_get_nickname() +  " registered successfully" << std::endl;
    }
    send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
}

void    Server::ft_private_msg_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    if (args.size() < 2)
    {
        std::string msg = "\033[0;31mIncomplete details provided for PRIVMSG command\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
		throw Server::IncompleteDetails(client);
    }
    else
    {
        std::vector<std::string> param = split_args(args[0]);
        std::vector<std::string>::iterator it;
        for (it = param.begin(); it != param.end(); it++)
        {
            Client *recipient = Server::ft_find_client(*it);
            if (recipient != nullptr)
                recipient->ft_send_message(args[args.size() - 1] + "\n");
            else
            {
                Channel *channel = Server::ft_find_channel(*it);
                if (channel == nullptr)
                {
                    std::string msg = *it + " is not a client or channel on this server\n";
                    send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
                    std::string error = "Server Error: No suck client or channel found for [" + *it + "]\n" ;
                    throw error;                    
                }
                if (channel->ft_client_exist(client->ft_get_nickname()))
                    channel->ft_send_message(args[args.size() - 1] + "\n", "", client, 0);
                else
                {
                    std::string msg = "\033[0;31mYou do not belong to this channel\033[0m\n";
                    send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
                    std::string error = "\033[0;31mServer Error: You do not belong on this channel\033[0m\n";
                    throw error;                     
                }
            }
        }
    }

}

void    Server::ft_user_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_get_password())
    {
        std::string msg = "\033[0;31mEnter correct password first\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::NoPasswordProvided(client);
    }

	if (args.size() != 4) 
    {
        std::string msg = "\033[0;31mIncomplete details provided for USER command\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
		throw Server::IncompleteDetails(client);
	}
	if (client->ft_check_if_registered())
    {
        std::string msg = "You are already authenticated\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
		throw Server::AlreadyAuthenticated(client);
	}
	client->ft_set_name(args[3]);
    client->ft_set_username(args[0]);
    client->bool_has_username(true);
    if (client->ft_check_if_nickname() && client->ft_check_if_username())
    {
        client->ft_set_registered(true);
        std::cout << "User @" + client->ft_get_nickname() +  " registered successfully" << std::endl;
    }
    std::cout << client->ft_get_fullname() << std::endl;
    std::cout << client->ft_get_username() << std::endl;
}

void    Server::ft_quit_command(std::vector<std::string> &args, Client *client)
{

    (void)args;
    Server::ft_remove_client(client);
    close(client->ft_get_socketFd());
    // this->ft_remove_pollfd(client->ft_get_socketFd());
}

void    Server::ft_kick_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    if (args.size() < 2)
    {
        std::string msg = "\033[0;31mIncomplete details provided for PART command\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::IncompleteDetails(client); 
    }
    Channel *channel = ft_find_channel(args.at(0));
    if (channel != nullptr)
    {
        if (channel->ft_is_an_operator(client))
        {
            Client  *client_kick = Server::ft_find_client(args[1]);
            if (client_kick != nullptr)
            {
                client_kick->ft_send_message("You have been Kicked out of " + channel->ft_get_channel());
                channel->ft_remove_client(client);
            }
            else
            {
                std::string msg = "\033[0;31mMo such client on the server\033[0m\n";
                send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
                std::string error = "\033[0;31mServer Error: Client does not exist\033[0m\n";
                throw error;
            }
        }
        else
        {
            std::string msg = "\033[0;31mYou are not an operator\033[0m\n";
            send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
            std::string error = "\033[0;31mServer Error: Access Denied\033[0m\n";
            throw error;
        }
        

    }
    else
    {
        std::string msg = "\033[0;31mINo Such Channel found\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "Channel " + args[0] + " does not exist on this server";
        throw error;
    }

}

void    Server::ft_pass_command(std::vector<std::string> &args, Client *client)
{
    if (client->ft_check_if_registered())
    {
        std::string msg = "You are already Authenticated\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::AlreadyAuthenticated(client);
    }
    if (args.empty())
    {
        std::string msg = "\033[0;31mIncomplete details provided for PASS command\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::IncompleteDetails(client);   
    }

    if (client->ft_get_password())
    {
        std::string msg = "\033[0;31mAlready provided PASSWORD\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
    }
    else
    {
        if (args[0] != this->_password)
        {
            std::string msg = "\033[0;31mIncorrect password provided\033[0m\n";
            send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
            throw Server::IncorrectPassword(client);
        }
    }

    client->ft_set_password(true);
    
}

void    Server::ft_topic_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    if (args.size() == 1 || args.size() == 2)
    {
        Channel *channel = Server::ft_find_channel(args[0]);
        if (channel != nullptr)
        {
            if (channel->ft_client_exist(client->ft_get_nickname()))
            {
                std::string topic;
                if (args.size() == 1)
                {
                    topic = channel->ft_get_topic();
                    send(client->ft_get_socketFd(), topic.c_str(), topic.size() + 1, 0); 
                }
                else if (args.size() == 2)
                    channel->ft_set_topic(args[1]);
            }
        }
        else
        {
            std::string msg = "\033[0;31mChannel does not exist on the server\033[0m\n";
            send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
            std::string error = "\033[0;31mServer Error: Channel not found\033[0m\n";
            throw error;
        }
    }
    else
    {
        std::string msg = "\033[0;31mIncomplete details provided for TOPIC command\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::IncompleteDetails(client); 
    }
    
}

void    Server::ft_notice_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    if (args.size() < 2)
    {
        std::string msg = "\033[0;31mIncomplete details provided for PRIVMSG command\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
		throw Server::IncompleteDetails(client);
    }
    else
    {
        std::vector<std::string> param = split_args(args[0]);
        std::vector<std::string>::iterator it;
        for (it = param.begin(); it != param.end(); it++)
        {
            Client *recipient = Server::ft_find_client(*it);
            if (recipient != nullptr)
                recipient->ft_send_message(args[args.size() - 1] + "\n");
            else
            {
                Channel *channel = Server::ft_find_channel(*it);
                if (channel == nullptr)
                {
                    std::string msg = *it + " is not a client or channel on this server\n";
                    send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
                    std::string error = "Server Error: No suck client or channel found for [" + *it + "]\n" ;
                    throw error;                    
                }
                if (channel->ft_client_exist(client->ft_get_nickname()))
                    channel->ft_send_message(args[args.size() - 1] + "\n", "", client, 0);
                else
                {
                    std::string msg = "\033[0;31mYou do not belong to this channel\033[0m\n";
                    send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
                    std::string error = "\033[0;31mServer Error: You do not belong on this channel\033[0m\n";
                    throw error;                     
                }
            }
        }
    }

}

void    Server::ft_ison_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    std::vector<std::string> clientNicknames = ft_get_args(args[0]);
    std::string result = "";
    std::vector<Client *>::iterator it;
    std::vector<Client *> clients = this->ft_get_all_clients();
    for (it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if (std::find(clientNicknames.begin(), clientNicknames.end(), (*it)->ft_get_nickname()) != clientNicknames.end())
            result += (*it)->ft_get_nickname() + " ";
    }
    client->ft_send_message(result);
   
}

void    Server::ft_list_command(std::vector<std::string> &args, Client *client)
{
    (void)args;
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    std::vector<Channel *>::iterator it;
    for (it = this->_channels.begin(); it != this->_channels.end(); it++)
    {
        std::string channelName = (*it)->ft_get_channel() + "\n";
        send(client->ft_get_socketFd(), channelName.c_str(),channelName.size() + 1, 0);
    }

}

void    Server::ft_part_command(std::vector<std::string> &args, Client *client)
{   
    if (!client->ft_check_if_registered())
    {
        std::string msg = "You are not registered to the server\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    if (args.size() != 1)
    {
        std::string msg = "\033[0;31mIncomplete details provided for PART command\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        throw Server::IncompleteDetails(client);   
    }
    std::vector<std::string> channelNames = split_args(args[0]);
    std::vector<std::string>::iterator it;
    for (it = channelNames.begin(); it != channelNames.end(); it++)
    {
        Channel *new_channel = Server::ft_find_channel(*it);
        if (new_channel == nullptr)
        {
            std::string msg = "This Channel does not exist\n";
            send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
            std::string error = "\033[0;31mServer Error: Channel does not exist on this server\033[0m\n";
            throw error;
        }
        if (new_channel->ft_client_exist(client->ft_get_nickname()))
        {
            new_channel->ft_remove_client(client);
            std::string msg = "You left #" + new_channel->ft_get_channel() +  "\n";
            send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
            if (new_channel->ft_empty_channel())
                Server::ft_delete_channel(new_channel->ft_get_channel());
        }
        else
        {
            std::string msg = "You are not on this channel\n";
            send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
            std::string error = "\033[0;31mServer Error:" + client->ft_get_nickname() + " does not belong on " + new_channel->ft_get_channel() + "\033[0m\n";
            throw error;
        }
    }
}


std::vector<std::string>    Server::ft_get_args(std::string argString)
{
	std::vector<std::string> args;
	std::string lastArg;
	size_t pos = 0;
	size_t newPos;

	newPos = argString.find("\r\n");
	if (newPos != std::string::npos) {
		argString = argString.substr(0, newPos);
	} else {
		newPos = argString.find('\n');
		if (newPos != std::string::npos) {
			argString = argString.substr(0, newPos);
		}
	}
	if (argString.empty()) {
		return args;
	}
	unsigned long spaceSkip = argString.length() - 1;
	while (argString[spaceSkip] == ' ' && spaceSkip != 0) {
		spaceSkip--;
	}
	if (spaceSkip != 0) {
		argString = argString.substr(0, spaceSkip + 1);
	}
	newPos = argString.find(':', 0);
	if (newPos != std::string::npos) {
		lastArg = argString.substr(newPos + 1);
		argString.erase(newPos);
	}
	int i;
	for (i = 0;; i++) {
		newPos = argString.find(' ', pos);
		if (newPos == std::string::npos) {
			args.push_back(argString.substr(pos, newPos - pos));
			break;
		}
		args.push_back(argString.substr(pos, newPos - pos));
		while (argString[newPos + 1] && argString[newPos + 1] == ' ') {
			newPos++;
		}
		pos = newPos + 1;
	}
	if (!lastArg.empty())
		args[i] = lastArg;
	return args;   
}

void    Server::ft_bot_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        std::string msg = "\033[0;31mYou are not registered to the server\033[0m\n";
        send(client->ft_get_socketFd(), msg.c_str(), msg.size() + 1, 0);
        std::string error = "\033[0;31mServer Error: Client not authenticated\033[0m\n";
        throw error;
    }
    std::cout << args[0] << std::endl;
    if (args.size() == 1)
    {

        Client *ircbot = Server::ft_find_client(std::string("IRCBOT"));
        if (ircbot != nullptr)
        {
            try
            {
                char buffer[4096];
                ircbot->ft_send_message(args[0]);
                usleep(100);
                recv(ircbot->ft_get_socketFd(), buffer, 4096, 0);
                client->ft_send_message(std::string(buffer));
            }
            catch(std::string &e)
            {
                std::cout << e << std::endl;
            }
        }
        else
        {
            std::cout << "Bot does not exist" << std::endl;
        }
            
    }
}