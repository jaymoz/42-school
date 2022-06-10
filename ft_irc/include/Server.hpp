#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/poll.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <cstdlib>
#include <sstream>
#include "Channel.hpp"
#include "Client.hpp"
#include "Exceptions.hpp"
#include "Replies.hpp"
#include "Utils.hpp"


class Client;

class Channel;

class Server
{
    private:
        int                         _socketFd;
        std::string&                _password;
        std::string&                _port;
        std::string                 _address;
        std::vector<Client *>       _clients;
        std::vector<Channel *>      _channels;
        std::vector<pollfd>         _fds;
        std::vector<std::string>    _commands;
        struct sockaddr_in          _server_address;

    public:
        Server(std::string &port, std::string &password);
        ~Server();
        void        ft_run_server();
        void        ft_create_socket();
        void        ft_bind_socket();
        void        ft_listen();
        void        ft_accept_connection();
        Client      *ft_getuser_by_socketFd(int fd);
        void        ft_remove_client(Client *client);
        void        use_password();
        std::string ft_recieve_msg(int fd);
        void        ft_handle_commands(Client *client, std::string &msg);
        void        ft_join_command(std::vector<std::string> &args, Client *client);
        void        ft_nick_command(std::vector<std::string> &args, Client *client);
        void        ft_private_msg_command(std::vector<std::string> &args, Client *client);
        void        ft_user_command(std::vector<std::string> &args, Client *client);
        void        ft_quit_command(std::vector<std::string> &args, Client *client);
        void        ft_kick_command(std::vector<std::string> &args, Client *client);
        void        ft_pass_command(std::vector<std::string> &args, Client *client);
        void        ft_topic_command(std::vector<std::string> &args, Client *client);
        void        ft_notice_command(std::vector<std::string> &args, Client *client);
        void        ft_ison_command(std::vector<std::string> &args, Client *client);
        void        ft_list_command(std::vector<std::string> &args, Client *client);
        void        ft_part_command(std::vector<std::string> &args, Client *client);
        void        ft_bot_command(std::vector<std::string> &args, Client *client);
        Channel     *ft_create_channel(Client *client, std::string channelname);
        void        ft_delete_channel(std::string channelname);
        Channel     *ft_find_channel(std::string channel);
        Client      *ft_find_client(std::string nickname);
        std::string &ft_get_host_address();
        std::vector<Client *> ft_get_all_clients();
        std::vector<std::string> ft_get_args(std::string argString);
        void        ft_remove_pollfd(int fd);
        void        send_msg_to_client(int client_fd, const std::string &msg);
        void        ft_send_hello(Client *client);

};

std::vector<std::string>    splitMultiString(std::string str);
std::vector<std::string>    str_split(std::string str, std::string delimiters);
std::vector<std::string>    str_parse(std::string str);
std::string                 str_ltrim(std::string str, const char* charset);
std::string                 str_rtrim(std::string str, const char* charset);
std::string                 str_trim(std::string str, const char* charset);
std::string                 str_toupper(std::string str);
std::string                 str_tolower(std::string str);

#endif