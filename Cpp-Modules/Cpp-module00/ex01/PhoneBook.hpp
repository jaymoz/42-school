#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
private:
	Contact	contact_list[8];
    int     total;

public:
    Phonebook();
	void	ft_add(int i);
	void	ft_search();
	void	ft_display();
    void    ft_start();
    void    ft_set_total();
};

#endif