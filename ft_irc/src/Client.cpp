#include "../include/Server.hpp"

Client::Client(int fd): _socketFd(fd),_isAuthenticated(false),_entered_password(false),_enteredNickname(false),_enteredUsername(false){}

Client:: ~Client(){}

void    Client::ft_send_message(std::string msg)
{
    if (send(this->_socketFd, msg.c_str(), msg.length(), 0) == -1)
        throw CustomException::FailedToSendMsg();

}

void    Client::ft_set_nickname(const std::string& nickname) {this->_nickname = nickname; }

bool    Client::ft_check_if_nickname(){return this->_enteredNickname; }

bool    Client::ft_check_if_username(){ return this->_enteredUsername; }

void    Client::ft_set_username(const std::string& username) {this->_username = username; }

void    Client::ft_set_password(bool val){ this->_entered_password = val; }

void    Client::ft_set_name(const std::string& name) { this->_fullName = name; }

void    Client::ft_set_registered(bool val) {this->_isAuthenticated = val; }

bool    Client::ft_check_if_registered() const { return this->_isAuthenticated; }

int     Client::ft_get_socketFd(){ return this->_socketFd; }

void    Client::bool_has_nickname(bool val){this->_enteredNickname = val; }

void    Client::bool_has_username(bool val){ this->_enteredUsername = val; }

bool    Client::ft_get_password(){ return this->_entered_password; }

std::string     Client::ft_get_nickname() {return this->_nickname; }

std::string     Client::ft_get_fullname() {return this->_fullName; }

std::string     Client::ft_get_username() {return this->_username; }

std::string     Client::fill_placeholders(const std::string &s, const std::string &comment,std::string host)
{
	std::string msg(s);

	ft_replace(msg, "<nick>", _nickname);
	ft_replace(msg, "<user>", _username);
	ft_replace(msg, "<server>", SERVER_NAME);
	ft_replace(msg, "<msg>", _send_msg);
    ft_replace(msg, "<online_nicks>", _online_nicks);
    ft_replace(msg, "<target>", _target);
	ft_replace(msg, "<comment>", comment);
    ft_replace(msg, "<host>", host);

	return msg;
}

void    Client::ft_add_channel(Channel *channel)
{
    this->_channels.push_back(channel);
}

void    Client::ft_leave_all_channel()
{
    for (size_t i = 0; i < this->_channels.size(); i++)
    {
        this->_channels[i]->ft_remove_client_by_nickname(this->_nickname);
        this->_channels.erase(this->_channels.begin() + i);
    }
}
