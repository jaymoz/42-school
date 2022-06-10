#include "Bot.hpp"

Bot::Bot(std::string host, std::string port, std::string pass) : _serverHost(host), _serverPort(port),_serverPass(pass)
{
    this->_nickname = "IRCBOT";
    this->_username = "IRCBOTv2";
    this->_realname = "THE JOKER";
    if (this->_serverHost == "localhost")
        this->_serverHost = "127.0.0.1";
}


void    Bot::ft_initialise_bot()
{
    int opt = 1;
    setsockopt(this->_socketFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
    this->_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->_socketFd == -1)
    {
        std::string err = "Bot Error: could not create socket";
        throw err;
    }
    this->_hint.sin_family = AF_INET;
    this->_hint.sin_port  = htons(stoi(this->_serverPort));
    this->_hint.sin_addr.s_addr = inet_addr(this->_serverHost.c_str());
    Bot::ft_set_jokes();

}

void    Bot::ft_connect()
{
    try
    {
        Bot::ft_initialise_bot();

    }
    catch (std::string &e)
    {
        std::cout << e << std::endl;
    }

    int ret = connect(this->_socketFd, (struct sockaddr *)&this->_hint, sizeof(this->_hint));
    if (ret == -1)
    {
        std::string err = "Bot Error: could not connect to the server";
        throw err;       
    }
    std::string pass = "PASS " + this->_serverPass + "\r\n";
    send(this->_socketFd, pass.c_str(), pass.size(), 0);
    usleep(100);
    std::string nick = "NICK " + this->_nickname + "\r\n";
    send(this->_socketFd, nick.c_str(), nick.size(), 0);
    usleep(100);
    std::string user = "USER IRCBOT * * : IRCBOT\r\n";
    send(this->_socketFd, user.c_str(), user.size(), 0);

    bool run = true;
    while (run)
    {
        char buffer[1024];
        std::memset(buffer, 0 ,1024);
        recv(this->_socketFd, buffer, 1024, 0);

        if (std::string(buffer).empty() || std::string(buffer) == "\r\n")
            continue;
        std::cout << buffer << std::endl;
        Bot::ft_process_commands(std::string(buffer));

    }
    close(this->_socketFd);
}


