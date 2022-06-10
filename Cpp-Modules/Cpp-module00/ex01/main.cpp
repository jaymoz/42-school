#include "PhoneBook.hpp"

int main(void)
{
    Phonebook   phonebook;
    std::string line;
    int i;

    i = 0;
    phonebook.ft_start();
    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "ADD")
        {
            phonebook.ft_add(i);
            i++;
            if (i == 8)
                i = 0;
        }
        else if (line == "SEARCH")
            phonebook.ft_search();
        else if (line == "EXIT")
            return (0);

    }
    return (0);
}