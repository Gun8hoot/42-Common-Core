
#ifndef HUMANA_H
# define HUMANA_H

# include <string>
# include "class/Weapon.hpp"

class HumanA
{
  private:
    std::string	name;
    Weapon &weapon;

  public:
    void	attack();
    void	setWeapon(Weapon weapon);
    HumanA(std::string name, Weapon &weapon);
};

#endif // !HUMANA_H
