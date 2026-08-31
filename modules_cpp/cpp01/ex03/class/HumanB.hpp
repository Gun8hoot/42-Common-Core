
#ifndef HUMANB_H
# define HUMANB_H

# include <string>
# include "class/Weapon.hpp"

class HumanB
{
  private:
    std::string name;
    Weapon *weapon;

  public:
    void	attack();
    void	setWeapon(Weapon *weapon);
    HumanB(std::string name);
};

#endif
