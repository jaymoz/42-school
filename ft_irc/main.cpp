#include "include/Server.hpp"

void    ft_check_param(std::string &port)
{
    try
    {
        int port_int = std::stoi(port);

        if (port_int < 1024 || port_int > 65535)
        {
            std::cout << "\033[0;31mPort Error: [1024 - 65536]\033[0m" << std::endl;
            exit(1);
        }

        for (size_t i = 0; i < port.size(); i++)
        {
            if (port[i] < 48 || port[i] > 57)
            {
                std::cout << "\033[0;31mPort Error: Expected only digits[1024 - 65536]\033[0m" << std::endl;
                exit(1);
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        std::string argv1 = std::string(argv[1]);
        std::string argv2 = std::string(argv[2]);
        ft_check_param(argv1);
        Server server(argv1, argv2);
        server.ft_run_server();
    }
    else
    {
        std::cout << "\033[0;31mError: ./ircserv [port] [password]\033[0m" << std::endl;
        exit(1);
    }

    return (0);
}