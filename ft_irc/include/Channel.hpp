#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <vector>
#include "Client.hpp"

class Client;

class Channel
{
    private:
        std::string             _channelName;
        std::string             _topic;
        std::vector<Client *>   _clients;
        std::vector<Client *>   _operators;
    public:
        Channel(std::string name);
        ~Channel();
        void                    ft_add_Client(Client *client);
        bool                    ft_client_exist(std::string clientNickname);
        void                    ft_remove_client(Client *client);
        void                    ft_set_topic(std::string topic);
        std::string             ft_get_topic();
        void                    ft_send_message(std::string message, std::string welcomemsg, Client *client, int key);
        void                    ft_add_operator(Client *client);
        std::string             ft_get_channel();
        bool                    ft_empty_channel();
        bool                    ft_is_an_operator(Client *client);
        void                    ft_remove_client_by_nickname(std::string nickName);
        void                    ft_send_message_to_channel(std::string message, Client *client);
};

#endif