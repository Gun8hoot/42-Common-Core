
#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
  private:
    std::string type;
  public:
    Weapon(std::string m_type);
    const std::string	&getType();
    void				setType(std::string new_type);
};

#endif // !WEAPON_H
