#include "../include/Server.hpp"

Server::Server(std::string &port, std::string &password): _password(password), _port(port)
{
    std::string arr[13] = {"JOIN","NICK","PRIVMSG","USER","QUIT","KICK","PASS","TOPIC","NOTICE","ISON", "LIST", "PART", "IRCBOT"};
    for (int i = 0; i < 13; i++)
        this->_commands.push_back(arr[i]);
}

Channel *Server::ft_find_channel(std::string channel)
{
	for (size_t i = 0; i < this->_channels.size(); i++) {
		if (channel == this->_channels[i]->ft_get_channel()) {
			return this->_channels[i];
		}
	}
	return nullptr;
}

Client  *Server::ft_find_client(std::string nickname)
{
	for (size_t i = 0; i < this->_clients.size(); i++) {
		if (this->_clients[i]->ft_get_nickname() == nickname)
			return this->_clients[i];
	}
	return nullptr;
}

Server::~Server(){}

void    Server::ft_delete_channel(std::string channelname)
{
    for (size_t i = 0; i < this->_channels.size(); i++)
    {
        if (channelname == this->_channels[i]->ft_get_channel())
        {
            this->_channels.erase(this->_channels.begin() + i);
            break;
        }
    }
}

void    Server::use_password(){ (void)_password; }

std::vector<Client *>   Server::ft_get_all_clients(){ return this->_clients; }

void    Server::ft_create_socket()
{
    this->_socketFd = socket(AF_INET, SOCK_STREAM, 0);

    if (this->_socketFd == -1)
        throw CustomException::FailedToCreateSocket();
}

void    Server::ft_bind_socket()
{
    this->_server_address.sin_family = AF_INET;
    this->_server_address.sin_port = htons(stoi(this->_port));
    this->_server_address.sin_addr.s_addr = INADDR_ANY;

    int val = 1;
    if (setsockopt(this->_socketFd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) == -1)
        throw CustomException::FailedSetSockOpt();

    if (fcntl(this->_socketFd, F_SETFL, O_NONBLOCK) == -1)
        throw CustomException::FailedFcntl();

    if (bind(this->_socketFd, (sockaddr *)&this->_server_address, sizeof(this->_server_address)) == -1)
        throw CustomException::FailedToBind();
   
}

void    Server::ft_listen()
{
    if (listen(this->_socketFd, SOMAXCONN) == -1)
        throw CustomException::FailedToListen();
}

void    Server::ft_accept_connection()
{
    int client_fd;
    sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    client_fd = accept(this->_socketFd, (sockaddr *)&client_addr, &client_addr_size);
    if (client_fd < 0)
        throw CustomException::FailedToAccept();
    pollfd client_poll_fd;
    client_poll_fd.fd = client_fd;
    client_poll_fd.events = POLLIN;
    client_poll_fd.revents = 0;

    this->_fds.push_back(client_poll_fd);

    Client *client = new Client(client_fd);
    this->_clients.push_back(client);
    std::cout << "\033[1;32mClient : [" << client->ft_get_socketFd() << "] connected to the the Server\033[0m\n";
}

Client  *Server::ft_getuser_by_socketFd(int fd)
{
    for (size_t i = 0; i < this->_clients.size(); i++)
    {
        if (fd == this->_clients[i]->ft_get_socketFd())
            return this->_clients[i];
    }
    return nullptr;
}

std::string Server::ft_recieve_msg(int fd)
{
    char msg[4096];
    size_t num_bytes;
    memset(msg, '\0', sizeof(msg));
    num_bytes = recv(fd, msg, sizeof(msg), 0);
    if (num_bytes <= 0)
        throw CustomException::FailedToRecieve();
    std::cout << "\033[1;32mClient : [" << fd << "]:\033[0m ";
    std::cout << "\033[0;33m";
    std::cout << msg;
    std::cout << "\033[0m " << std::endl;
    return (msg);
}

void    Server::ft_remove_client(Client *client)
{
    for (size_t i = 0; i != this->_clients.size(); i++)
    {
        if (client == this->_clients[i])
        {
            this->_clients[i]->ft_leave_all_channel();
            this->_clients.erase(this->_clients.begin() + i);
            break;
        }
    }
}

void    Server::ft_run_server()
{
    try
    {
        Server::ft_create_socket();
        Server::ft_bind_socket();
        Server::ft_listen();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    pollfd server_poll_fd;
    server_poll_fd.fd = this->_socketFd;
    server_poll_fd.events = POLLIN;
    server_poll_fd.revents = 0;

    this->_fds.push_back(server_poll_fd);
    while (true)
    {
        try
        {
            if (poll(this->_fds.begin().base(), this->_fds.size(), -1) < 0)
                throw CustomException::FailedToPoll();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::vector<pollfd>::iterator it;

        for (it = this->_fds.begin(); it != this->_fds.end(); it++)
        {
            if (it->revents == 0)
                continue;
            
            if ((it->revents & POLLHUP) == POLLHUP)
            {
                Client *client = ft_getuser_by_socketFd(it->fd);
                if (client == nullptr)
                    continue;
                std::cout << "\033[0;31mClient : [";
                std::cout << client->ft_get_socketFd() <<  "] disconnected from the Server\033[0m" << std::endl;
                this->ft_remove_client(client);
                close(it->fd);
                it = _fds.erase(it);
                if (it == _fds.end())
                    break ;
                
            }
            if ((it->revents & POLLIN) == POLLIN)
            {
                if (it->fd == this->_socketFd)
                {
                    try
                    {
                        int client_fd;
                        sockaddr_in client_addr;
                        socklen_t client_addr_size = sizeof(client_addr);

                        client_fd = accept(this->_socketFd, (sockaddr *)&client_addr, &client_addr_size);
                        if (client_fd < 0)
                            continue ;
                        pollfd client_poll_fd;
                        client_poll_fd.fd = client_fd;
                        client_poll_fd.events = POLLIN;
                        client_poll_fd.revents = 0;

                        this->_fds.push_back(client_poll_fd);

                        Client *client = new Client(client_fd);
                        this->_clients.push_back(client);
                        std::cout << "\033[1;32mClient : [" << client->ft_get_socketFd() << "] connected to the the Server\033[0m\n";
                            break ;
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << std::endl;
                    }
                }
                else
                {
                    Client *currClient = ft_getuser_by_socketFd(it->fd);
                    try
                    {
                        std::string ClientMsg = Server::ft_recieve_msg(currClient->ft_get_socketFd());
                        Server::ft_handle_commands(currClient, ClientMsg);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << std::endl;
                    }
                    

                }

            }
        }
    }
}

void    Server::ft_handle_commands(Client *client, std::string &msg)
{
    void (Server::*funcptr[13])(std::vector<std::string> &args, Client *client) = 
    {
        &Server::ft_join_command, &Server::ft_nick_command,
        &Server::ft_private_msg_command,&Server::ft_user_command,
        &Server::ft_quit_command,&Server::ft_kick_command,
        &Server::ft_pass_command,&Server::ft_topic_command,
        &Server::ft_notice_command,&Server::ft_ison_command,
        &Server::ft_list_command, &Server::ft_part_command,
        &Server::ft_bot_command
    };

	std::vector<std::string> cmd_line = str_split(msg, "\n");
	for (size_t i = 0; i < cmd_line.size(); i++)
	{
		if (cmd_line[i].length() == 0)
			continue;

		std::cout << cmd_line[i] << std::endl;

		std::vector<std::string> cmd_args = str_parse(cmd_line[i]);
		for (size_t j = 0; j < cmd_args.size(); j++)
			cmd_args[j] = str_trim(cmd_args[j], " \n\t\r\f\v");
		std::string cmd_name = str_trim(cmd_args[0], " \n\t\v\f\r");
        std::cout << cmd_name << std::endl;
        cmd_args.erase(cmd_args.begin());
        try 
        {
            for (size_t k = 0; k < 13; k++)
            {
                if (cmd_name == this->_commands[k])
                {
                    (this->*funcptr[k])(cmd_args, client);
                    break ;
                }
            }
        }
        catch (std::string &e)
        {
            std::cout << e << std::endl;
        }

	}
}

void Server::ft_remove_pollfd(int fd) 
{
	for (unsigned int i = 0; i < _fds.size(); i++) {
		if (fd == _fds[i].fd) {
			this->_fds.erase(_fds.begin() + i);
			break;
		}
	}
}