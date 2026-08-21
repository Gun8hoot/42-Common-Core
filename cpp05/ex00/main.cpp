
#include "Bureaucrat.hpp"

#include <stdexcept>
#include <iostream>

int main(void)
{
	Bureaucrat user;
	Bureaucrat user2("user2", 44);
  #ifdef DEBUG
  std::cout << user.getName() << " " << user.getGrade() << std::endl;
  std::cout << user2.getName() << " " << user2.getGrade() << std::endl;
  #endif

	{
		std::cout << "\x1b[1m\x1b[0;32mIf the grade overflow the lowest value : \n\x1b[0m\x1b[0m";
		try
		{
			user.setGrade(152);
			std::cout << user;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	{
		std::cout << "\n\x1b[1m\x1b[0;32mIf the grade overflow the highest value : \n\x1b[0m";
		try
		{
			user2.setGrade(-5);
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	{
		std::cout << "\n\x1b[1m\x1b[0;32mPre increse on the grade : \n\x1b[0m";
		try
		{
			user.setGrade(75);
			std::cout << user;
			++user;
			std::cout << user;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	{
		std::cout << "\n\x1b[1m\x1b[0;32mPost increse on the grade : \n\x1b[0m";
		try
		{
			user.setGrade(75);
			std::cout << user;
			user++;
			std::cout << user;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	{
		std::cout << "\n\x1b[1m\x1b[0;32mPre decrease on the grade : \n\x1b[0m";
		try
		{
			user2.setGrade(75);
			std::cout << user2;
			--user2;
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	{
		std::cout << "\n\x1b[1m\x1b[0;32mPost decrease on the grade : \n\x1b[0m";
		try
		{
			user2.setGrade(75);
			std::cout << user2;
			user2--;
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	{
		std::cout << "\n\x1b[1m\x1b[0;32mTrying to decrease the highest value grade : \n\x1b[0m";
		try
		{
			user2.setGrade(1);
			std::cout << user2;
			--user2;
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	{
		std::cout << "\n\x1b[1m\x1b[0;32mTrying to increase the lowest value grade : \n\x1b[0m";
		try
		{
			user2.setGrade(150);
			std::cout << user2;
			++user2;
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
}
