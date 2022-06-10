#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
    this->total = 0;
}

void    Phonebook::ft_add(int i)
{
    std::string	input;

    if (this->total == 8)
        std::cout << "Phonebook full!!! replacing oldest contact  \n";
    std::cout << "First name: ";
    std::getline(std::cin, input);
    contact_list[i].ft_setFirstName(input);
    std::cout << "Last name: ";
    std::getline(std::cin, input);
    contact_list[i].ft_setLastName(input);
    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    contact_list[i].ft_setNickname(input);
    std::cout << "Phonenumber: ";
    std::getline(std::cin, input);
    contact_list[i].ft_setPhoneNumber(input);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    contact_list[i].ft_setDarkestSecret(input);
    this->total++;
    std::cout <<"Contact Created" << std::endl;

}

void	Phonebook::ft_display() {
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		(contact_list[i].ft_getFirstName().length() > 10) ? std::cout << std::setw(10) << contact_list[i].ft_getFirstName().substr(0, 9) + "." << "|" : std::cout << std::setw(10) << contact_list[i].ft_getFirstName() << "|";
		(contact_list[i].ft_getLastName().length() > 10) ? std::cout << std::setw(10) << contact_list[i].ft_getLastName().substr(0, 9) + "." << "|" : std::cout << std::setw(10) << contact_list[i].ft_getLastName() << "|";
		(contact_list[i].ft_getNickName().length() > 10) ? std::cout << std::setw(10) << contact_list[i].ft_getNickName().substr(0, 9) + "." << std::endl : std::cout << std::setw(10) << contact_list[i].ft_getNickName() << std::endl;
	}
}


void	Phonebook::ft_search() {
	std::string index;
    int         ret;

    if (this->total == 0)
    {
        std::cout << "no contacts to show. ADD a contact" << std::endl;
    }
    else
    {
        ft_display();
        while (1) {
            std::cout << "Enter an index: ";
            std::cin >> index;
            if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
                break ;
            else {
                std::cout << "Invalid Index" << std::endl;
            }
        }
        ret = index[0] - 48;
        contact_list[ret - 1].output_contact();
    }

}

void    Phonebook::ft_start()
{
        std::cout << "Welcome to my Phone Book 📘 🤩" << std::endl
        << "Here are basic operations you can perform 😊" <<std::endl
        << "ADD, SEARCH, EXIT" << std::endl;
}