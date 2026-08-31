#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "wrongAnimal.hpp"

int	main(void)
{
	const Animal		*Neko = new Cat();
	const Animal		*Dogo = new Dog();
	const Animal		*Zarbi = new Animal();
	const wrongAnimal	*wawa = new wrongAnimal();

	std::cout << std::endl;

	Zarbi->makeSound();
	Dogo->makeSound();
	Neko->makeSound();
	wawa->makeSound();

	std::cout << std::endl;

	delete Neko;
	delete Dogo;
	delete Zarbi;
	delete wawa;
}
