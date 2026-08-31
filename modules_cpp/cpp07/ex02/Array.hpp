
# pragma once

#include <cstdlib>
#include <exception>
#include <iostream>
#include <cstring>

template <typename T>
class Array {
	private:
		std::size_t	_nb_element;
		T			*_ptr;
	public:
		// -- CONSTRUCTOR --
		~Array(void)
		{
			if (this->_ptr != NULL)
				delete [] this->_ptr;
			this->_nb_element = 0;
		}
		Array(void) : _nb_element(0), _ptr(NULL)
		{
			try
			{
				_ptr = new T[0]; // Allocated an empty array, gcc = -Wno-alloc-size
			}
			catch (std::bad_alloc &ex)
			{
				std::cout << "Failed to allocated memory" << std::endl;
			}
		};
		Array(unsigned int n) : _nb_element(n), _ptr(NULL)
		{
			try
			{
				_ptr = new T[n];
				std::memset(_ptr, '\0', n * sizeof(T));
			}
			catch (std::bad_alloc &ex)
			{
				std::cout << "Failed to allocated memory" << std::endl;
			}
		};
		Array(const Array &cpy) : _nb_element(cpy._nb_element) , _ptr(NULL)
		{
			try
			{
				if (this != &cpy)
				{
					if (this->_ptr != NULL)
						delete[] this->_ptr;
					this->_ptr = new T[cpy._nb_element];
					std::memcpy(this->_ptr, cpy._ptr, cpy._nb_element * sizeof(T));
				}
			}
			catch (std::bad_alloc &ex)
			{
				std::cout << "Failed to allocated memory" << std::endl;
			}
		};
		Array &operator=(const Array &cpy)
		{
			if (this != &cpy)
			{
				if (this->_ptr != NULL)
					delete[] this->_ptr;
				this->_nb_element = cpy._nb_element;
				this->_ptr = cpy._ptr;
			}
			return (*this);
		};

		// -- OPERATOR OVERLOAD --
		const T &operator[](std::size_t i) const
		{
			if (i >= this->_nb_element)
				throw (std::out_of_range("You are going out of bound of the array"));
			return (this->_ptr[i]);;
		}

		T &operator[](std::size_t i)
		{
			if (i >= this->_nb_element)
				throw (std::out_of_range("You are going out of bound of the array"));
			return (this->_ptr[i]);;
		}

		// -- METHODE --
		std::size_t	size(void)
		{
			return (this->_nb_element);
		};
};
