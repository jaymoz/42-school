#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

class CustomException
{
    public:
        class FailedToBind : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: could not bind socket to IP and port\033[0m";
                }
        };

        class FailedSetSockOpt : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: could not set setsockopt()\033[0m";
                }
        };

        class FailedFcntl : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: could not set socket to NON-BLOCKING\033[0m";
                }
        };

        class FailedToListen : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: failed to listen for connections\033[0m";
                }
    
        };

        class FailedToAccept : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: could not accept connection\033[0m";
                }
        };

        class FailedToRecieve : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mrecv(): failed to receive message from client\033[0m";
                }
        };

        class FailedToPoll : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: call to poll failed!!!\033[0m";
                }
        };

        class FailedToSendMsg : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: failed to send message on client socket\033[0m";
                }
        };

        class FailedToCreateSocket : public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "\033[0;31mServer Error: Could not create socket!!!\033[0m";
                }
        };


};

#endif