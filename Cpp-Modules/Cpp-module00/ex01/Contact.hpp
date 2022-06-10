#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        std::string	ft_getFirstName();
        std::string	ft_getLastName();
        std::string	ft_getNickName();
        std::string	ft_getPhoneNumber();
        std::string	ft_getDarkestSecret();

        void    ft_setFirstName(std::string first);
        void	ft_setLastName(std::string last);
        void	ft_setNickname(std::string nick);
        void	ft_setPhoneNumber(std::string phone);
        void	ft_setDarkestSecret(std::string secret);

        void	output_contact();       

};
#endif