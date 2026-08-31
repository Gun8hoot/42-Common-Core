#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "wrongAnimal.hpp"

void	clean(Animal **arr, int i)
{
	for (int j = 0; j < i; j++)
	{
		if (arr[j])
			delete arr[j];
	}
}

int	main(void)
{
	Animal **arr = new Animal*[10]();
	for (int i = 0; i < 5; i++)
	{
		arr[i] = new Cat();
		if (!arr[i])
		{
			clean(arr, i);
			return (1);
		}
	}
	for (int i = 5; i < 10; i++)
	{
		arr[i] = new Dog();
		if (!arr[i])
		{
			clean(arr, i);
			return (1);
		}
	}
	arr[2]->makeSound();
	arr[4]->makeSound();
	arr[5]->makeSound();
	arr[8]->makeSound();
	for (int i = 0; i < 10; i++)
	{
		if (arr[i])
			delete arr[i];
	}
	if (arr)
		delete[] arr;
}
