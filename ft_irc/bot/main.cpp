#include "Bot.hpp"

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        std::string host = std::string(argv[1]);
        std::string port = std::string(argv[2]);
        std::string pass = std::string(argv[3]);
        Bot bot(host, port, pass);
        try
        {
            bot.ft_connect();
        }
        catch (std::string &e)
        {
            std::cout << e << std::endl;
        }
    }
    else
    {
        std::cout << "\033[0;31mBot Error: ./ircbot [host] [port] [password]\033[0m" << std::endl;
        exit(1);
    }

    return (0);
}