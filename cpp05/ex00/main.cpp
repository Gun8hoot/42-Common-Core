
#include "Bureaucrat.hpp"

#include <stdexcept>
#include <iostream>

int main(void)
{
	Bureaucrat user("user");
	Bureaucrat user2("user2");

	{
		std::cout << "\x1b[1mIf the grade overflow the lowest value : \n\x1b[0m\x1b[0m";
		try
		{
			user.setGrade(152);
			std::cout << user;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what();
		}
	}

	{
		std::cout << "\n\x1b[1mPre increse on the grade : \n\x1b[0m";
		try
		{
			user.setGrade(75);
			++user;
			std::cout << user;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what();
		}
	}

	{
		std::cout << "\n\x1b[1mPost increse on the grade : \n\x1b[0m";
		try
		{
			user.setGrade(75);
			user++;
			std::cout << user;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what();
		}
	}

	{
		std::cout << "\n\x1b[1mIf the grade overflow the highest value : \n\x1b[0m";
		try
		{
			user2.setGrade(-5);
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what();
		}
	}

	{
		std::cout << "\n\x1b[1mPre decrease on the grade : \n\x1b[0m";
		try
		{
			user2.setGrade(75);
			--user2;
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what();
		}
	}

	{
		std::cout << "\n\x1b[1mPost decrease on the grade : \n\x1b[0m";
		try
		{
			user2.setGrade(75);
			user2--;
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what();
		}
	}

	{
		std::cout << "\n\x1b[1mTrying to decrease the highest value grade : \n\x1b[0m";
		try
		{
			user2.setGrade(1);
			user2--;
			std::cout << user2;
		}
		catch (std::exception &exc)
		{
			std::cout << exc.what();
		}
	}
}
