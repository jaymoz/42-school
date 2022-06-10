#include "Contact.hpp"

void	Contact::ft_setFirstName(std::string first) {this->first_name = first;}
void	Contact::ft_setLastName(std::string last) {this->last_name = last;}
void	Contact::ft_setNickname(std::string nick) {this->nickname = nick;}
void	Contact::ft_setPhoneNumber(std::string phone) {this->phone_number = phone;}
void	Contact::ft_setDarkestSecret(std::string secret) {this->darkest_secret = secret;}

std::string	Contact::ft_getFirstName() {return (this->first_name);}
std::string	Contact::ft_getLastName() {return (this->last_name);}
std::string	Contact::ft_getNickName() {return (this->nickname);}
std::string	Contact::ft_getPhoneNumber() {return (this->phone_number);}
std::string	Contact::ft_getDarkestSecret() {return (this->darkest_secret);}

void	Contact::output_contact() {
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}
