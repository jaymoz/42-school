#include "../include/Server.hpp"


Channel::Channel(std::string name) : _channelName(name) {}

Channel::~Channel(){}

std::string Channel::ft_get_channel(){ return this->_channelName; }

void    Channel::ft_set_topic(std::string topic){ this->_topic = topic; }

std::string Channel::ft_get_topic(){ return this->_topic; }

void    Channel::ft_send_message(std::string message, std::string welcomemsg, Client *client, int key)
{
    std::vector<Client *>::iterator it;
    for (it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if (key == 0)
        {
            if ((*it) != client)
                (*it)->ft_send_message(message);
        }
        else if (key == 1)
        {
            if ((*it) == client)
                (*it)->ft_send_message(welcomemsg);
        }

    }
    // (void)message;
}

void    Channel::ft_send_message_to_channel(std::string message, Client *client)
{
    std::vector<Client *>::iterator it;
    for (it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if ((*it) != client)
            (*it)->ft_send_message(message);

    }
}

void    Channel::ft_add_operator(Client *client)
{
    std::vector<Client *>::iterator it;

    for (it = this->_operators.begin(); it != this->_operators.end(); it++)
    {
        if ((*it)->ft_get_socketFd() == client->ft_get_socketFd())
        {
            return ;
        }
    }
    this->_operators.push_back(client);
}

void    Channel::ft_add_Client(Client *client)
{
    std::vector<Client *>::iterator it;

    for (it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if ((*it)->ft_get_socketFd() == client->ft_get_socketFd())
        {
            return ;
        }
    }
    this->_clients.push_back(client);
}

bool    Channel::ft_client_exist(std::string clientNickname)
{
	for (size_t i = 0; i < this->_clients.size(); i++)
    {
		if (this->_clients[i]->ft_get_nickname() == clientNickname) {
			return true;
		}
	}
	return false;   
}

void    Channel::ft_remove_client(Client *client)
{
    std::vector<Client *>::iterator it;
    for (it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if ((*it)->ft_get_socketFd() == client->ft_get_socketFd())
        {
            this->_clients.erase(it);
            return ;
        }
    } 
}

void    Channel::ft_remove_client_by_nickname(std::string nickName)
{
    std::vector<Client *>::iterator it;
    int i = 0;
    for (it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if ((*it)->ft_get_nickname() == nickName)
            break;
        i++;

    }
    this->_clients.erase(this->_clients.begin() + i);
}

bool    Channel::ft_empty_channel()
{
	if (this->_clients.empty())
		return true;
	return false;
}

bool  Channel::ft_is_an_operator(Client *client)
{
    for (size_t i = 0; i < this->_operators.size(); i++)
    {
        if (this->_operators[i] == client)
            return true;
    }
    return false;
}