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

void    Server::ft_join_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
    }
    if (args.size() != 1)
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ; 
  
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
        std::string msg = client->fill_placeholders(JOIN, new_channel->ft_get_channel(),this->ft_get_host_address());
        Server::send_msg_to_client(client->ft_get_socketFd(), msg);
        std::string new_msg = RPL_TOPIC;
        ft_replace(new_msg, "<channel>", new_channel->ft_get_channel());
        ft_replace(new_msg, "<topic>", new_channel->ft_get_topic());
        Server::send_msg_to_client(client->ft_get_password(), new_msg);
    }
}

void    Server::ft_nick_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_get_password())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOPASSWORD,this->ft_get_host_address()));
        return ; 
    }
    if (args.empty())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NONICKNAMEGIVEN,this->ft_get_host_address()));
        return ;
    }

    for (size_t i = 0; i < this->_clients.size(); i++)
    {
        if (this->_clients[i]->ft_get_nickname() == args[0])
        {
            Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NICKNAMEINUSE,this->ft_get_host_address()));
            return ;
        }
    }
    client->ft_set_nickname(args[0]);
    client->bool_has_nickname(true);
    if (client->ft_check_if_nickname() && client->ft_check_if_username())
    {
        client->ft_set_registered(true);
        Server::ft_send_hello(client);
    }
}

void    Server::ft_private_msg_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
    }
    if (args.size() < 2)
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ; 
    }
    else
    {
        std::vector<std::string> param = split_args(args[0]);
        std::vector<std::string>::iterator it;
        for (it = param.begin(); it != param.end(); it++)
        {
            Client *recipient = Server::ft_find_client(*it);
            if (recipient != nullptr)
            {
                if (recipient->ft_get_nickname() != client->ft_get_nickname())
                {
                    client->_target = recipient->ft_get_nickname();
                    client->_send_msg = args[args.size() - 1];
                    recipient->ft_send_message(client->fill_placeholders(MESSAGE,this->ft_get_host_address()));
                }
            }  
            else
            {
                Channel *channel = Server::ft_find_channel(*it);
                if (channel == nullptr)
                {
                    Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOSUCHNICK,this->ft_get_host_address()));
                    return ;                      
                }
                if (channel->ft_client_exist(client->ft_get_nickname()))
                {
                    client->_send_msg = args[args.size() - 1];
                    client->_target = channel->ft_get_channel();
                    channel->ft_send_message(client->fill_placeholders(MESSAGE,this->ft_get_host_address()), "", client, 0);

                }
                else
                {
                    Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTONCHANNEL,this->ft_get_host_address()));
                    return ;   
                }
            }
        }
    }

}

void    Server::ft_user_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_get_password())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOPASSWORD,this->ft_get_host_address()));
        return ;
    }

	if (args.size() != 4) 
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ;
	}
	if (client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_ALREADYREGISTRED,this->ft_get_host_address()));
        return ;
	}
	client->ft_set_name(args[3]);
    client->ft_set_username(args[0]);
    client->bool_has_username(true);
    if (client->ft_check_if_nickname() && client->ft_check_if_username())
    {
        client->ft_set_registered(true);
        Server::ft_send_hello(client);
    }

}

void    Server::ft_quit_command(std::vector<std::string> &args, Client *client)
{

    (void)args;
    Server::ft_remove_client(client);
    close(client->ft_get_socketFd());
    std::cout << "\033[0;31mClient : [";
    std::cout << client->ft_get_socketFd() <<  "] disconnected from the Server\033[0m" << std::endl;
    delete client;
}

void    Server::ft_kick_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
    }
    if (args.size() < 2)
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ; 
    }
    Channel *channel = ft_find_channel(args.at(0));
    if (channel != nullptr)
    {
        if (channel->ft_is_an_operator(client))
        {
            Client  *client_kick = Server::ft_find_client(args[1]);
            if (client_kick != nullptr)
            {
                channel->ft_remove_client(client);
                std::string msg = MESSAGE;
                client->_send_msg = "you were kicked out from " + channel->ft_get_channel();
                Server::send_msg_to_client(client_kick->ft_get_socketFd(), client->fill_placeholders(msg,this->ft_get_host_address()));
            }
            else
            {
                Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOSUCHNICK,this->ft_get_host_address()));
                return ; 
            }
        }
        else
        {
            std::string msg = ERR_CHANOPRIVSNEEDED;
            ft_replace(msg, "<channel>", channel->ft_get_channel());
            Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(msg,this->ft_get_host_address()));
        }
    }
    else
    {
        std::string msg = ERR_NOSUCHCHANNEL;
        ft_replace(msg, "<channel>", channel->ft_get_channel());
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(msg,this->ft_get_host_address()));
        return ; 
    }

}

void    Server::ft_pass_command(std::vector<std::string> &args, Client *client)
{
    if (client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_ALREADYREGISTRED,this->ft_get_host_address()));
        return ;
    }
    if (args.empty())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ;
    }

    if (client->ft_get_password())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_ALREADYTYPEDPASSWORD,this->ft_get_host_address()));
        return ;
    }
    else
    {
        if (args[0] != this->_password)
         {
             Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_PASSWDMISMATCH,this->ft_get_host_address()));
             return ;
         }
    }

    client->ft_set_password(true);
    
}

void    Server::ft_topic_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
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
                    std::string msg = RPL_TOPIC;
                    ft_replace(msg, "<channel>", channel->ft_get_channel());
                    ft_replace(msg, "<topic>", topic);
                    Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(msg,this->ft_get_host_address())); 
                }
                else if (args.size() == 2)
                    channel->ft_set_topic(args[1]);
            }
        }
        else
        {
            std::string msg = ERR_NOSUCHCHANNEL;
            ft_replace(msg, "<channels>", args[0]);
            Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(msg,this->ft_get_host_address()));
            return ; 
        }
    }
    else
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ; 
    }
    
}

void    Server::ft_notice_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
    }
    if (args.size() < 2)
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ; 
    }
    else
    {
        std::vector<std::string> param = split_args(args[0]);
        std::vector<std::string>::iterator it;
        for (it = param.begin(); it != param.end(); it++)
        {
            Client *recipient = Server::ft_find_client(*it);
            if (recipient != nullptr)
            {
                client->_target = recipient->ft_get_nickname();
                client->_send_msg = args[args.size() - 1];
                recipient->ft_send_message(client->fill_placeholders(MESSAGE,this->ft_get_host_address()));
            }  
            else
            {
                Channel *channel = Server::ft_find_channel(*it);
                if (channel == nullptr)
                {
                    Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOSUCHCHANNEL,this->ft_get_host_address()));
                    return ;                      
                }
                if (channel->ft_client_exist(client->ft_get_nickname()))
                {
                    client->_send_msg = args[args.size() - 1];
                    channel->ft_send_message(client->fill_placeholders(MESSAGE,this->ft_get_host_address()), "", client, 0);

                }
                else
                {
                    Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTONCHANNEL,this->ft_get_host_address()));
                    return ;   
                }
            }
        }
    }

}

void    Server::ft_ison_command(std::vector<std::string> &args, Client *client)
{
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
    }
    std::vector<std::string> clientNicknames = ft_get_args(args[0]);
    client->_online_nicks.clear();
    std::vector<Client *>::iterator it;
    std::vector<Client *> clients = this->ft_get_all_clients();
    for (it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if (std::find(clientNicknames.begin(), clientNicknames.end(), (*it)->ft_get_nickname()) != clientNicknames.end())
            client->_online_nicks += (*it)->ft_get_nickname() + " ";
    }
    if (!client->_online_nicks.empty())
        client->_online_nicks.pop_back();
    std::string msg = client->fill_placeholders(RPL_ISON,this->ft_get_host_address());
    Server::send_msg_to_client(client->ft_get_socketFd(), msg);
   
}

void    Server::ft_list_command(std::vector<std::string> &args, Client *client)
{
    (void)args;
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
    }
    std::vector<Channel *>::iterator it;
    for (it = this->_channels.begin(); it != this->_channels.end(); it++)
    {
        std::string channelName = (*it)->ft_get_channel();
        client->_online_nicks += channelName + " ";
    }
    if (!client->_online_nicks.empty())
        client->_online_nicks.pop_back();
    std::string msg = client->fill_placeholders(RPL_ISON,this->ft_get_host_address());
    Server::send_msg_to_client(client->ft_get_socketFd(), msg);
    

}

void    Server::ft_part_command(std::vector<std::string> &args, Client *client)
{   
    if (!client->ft_check_if_registered())
    {
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED,this->ft_get_host_address()));
        return ; 
    }
    if (args.size() != 1)
    {
       Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NEEDMOREPARAMS,this->ft_get_host_address()));
        return ;   
    }
    std::vector<std::string> channelNames = split_args(args[0]);
    std::vector<std::string>::iterator it;
    for (it = channelNames.begin(); it != channelNames.end(); it++)
    {
        Channel *new_channel = Server::ft_find_channel(*it);
        if (new_channel == nullptr)
        {
            Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOSUCHCHANNEL,this->ft_get_host_address()));
            return ;  
        }
        if (new_channel->ft_client_exist(client->ft_get_nickname()))
        {
            new_channel->ft_remove_client(client);
            std::cout << client->ft_get_nickname() << " left " << new_channel->ft_get_channel();
            if (new_channel->ft_empty_channel())
                Server::ft_delete_channel(new_channel->ft_get_channel());
        }
        else
        {
            Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTONCHANNEL,this->ft_get_host_address()));
            return ;  
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
        Server::send_msg_to_client(client->ft_get_socketFd(), client->fill_placeholders(ERR_NOTREGISTERED));
        return ; 
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