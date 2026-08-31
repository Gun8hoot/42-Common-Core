
#ifndef MAIN_H
# define MAIN_H

// --- Includes ---
#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <sstream>
#include "includes/class/PhoneBook.hpp"
#include "includes/class/Contact.hpp"

// --- prototypes ---
void  commande(std::string line, PhoneBook &phonebook);
void  show_contact(PhoneBook phonebook);
void  add(PhoneBook &phonebook);
void  search(PhoneBook phonebook);
int	stoi(std::string toConvert, int &num);

#endif
