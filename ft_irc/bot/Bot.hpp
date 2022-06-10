#ifndef FT_IRC_BOT_HPP
#define FT_IRC_BOT_HPP

# include <iostream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <poll.h>
# include <vector>
# include <algorithm>
# include <unistd.h>
# include <time.h>

class Bot
{
    private:
        int                         _socketFd;
        std::string                 _nickname;
        std::string                 _realname;
        std::string                 _username;
        std::string                 _serverHost;
        std::string                 _serverPort;
        std::string                 _serverPass;
        std::vector<std::string>    _jokes;
        struct sockaddr_in          _hint;
    public:
        Bot(std::string host, std::string port, std::string pass);
        void    ft_initialise_bot();
        void    ft_connect();
        void    ft_set_jokes();
        void    ft_joke_command();
        void    ft_help_command();
        void    ft_info_command();
        void    ft_process_commands(std::string arg);
        std::vector<std::string> split_args(std::string args);
};


#endif 