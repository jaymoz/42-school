#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <vector>
#include "Channel.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"
#include "Server.hpp"

class Channel;

class Client
{
    private:
        int                     _socketFd;
        std::string             _nickname;
        std::string             _username;
        std::string             _fullName;
        std::vector<Channel *>  _channels;
        bool                    _isAuthenticated;
        bool                    _entered_password;
        bool                    _enteredNickname;
        bool                    _enteredUsername;
    public:
        std::string             _online_nicks;
        std::string             _target;
        std::string             _send_msg;
        Client(int fd);
        ~Client();
        void            ft_send_message(std::string msg);
        void            ft_set_nickname(const std::string& nickname);
        void            ft_set_username(const std::string& username);
        void            ft_set_name(const std::string& name);
        void            ft_set_password(bool val);
        void            ft_set_registered(bool val);
        bool            ft_check_if_registered() const;
        void            ft_add_channel(Channel *channel);
        bool            ft_get_password();
        bool            ft_check_if_nickname();
        bool            ft_check_if_username();
        void            ft_leave_all_channel();
        int             ft_get_socketFd();
        void            bool_has_nickname(bool val);
        void            bool_has_username(bool val);
        std::string     ft_get_nickname();
        std::string     ft_get_username();
        std::string     ft_get_fullname();
        std::string     fill_placeholders(const std::string &s, const std::string &comment="", std::string host="127.0.0.1");


};

#endif