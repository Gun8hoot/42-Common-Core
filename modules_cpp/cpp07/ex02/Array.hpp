#pragma once

#include <cstddef>      // std::size_t
#include <stdexcept>    // std::out_of_range
#include <new>          // std::bad_alloc

template <typename T>
class Array
{
private:
	std::size_t _size;
	T          *_ptr;

public:
	// --- Orthodox Canonical Form ---
	Array(void) : _size(0), _ptr(NULL) {}

	Array(unsigned int n) : _size(n), _ptr(NULL)
	{
		if (_size > 0)
			_ptr = new T[_size]();
	}

	Array(const Array &cpy) : _size(cpy._size), _ptr(NULL)
	{
		if (_size > 0)
		{
			_ptr = new T[_size]();
			for (std::size_t i = 0; i < _size; ++i)
				_ptr[i] = cpy._ptr[i];
		}
	}

	Array &operator=(const Array &cpy)
	{
		if (this != &cpy)
		{
			delete[] _ptr;
			_size = cpy._size;
			if (_size > 0)
			{
				_ptr = new T[_size]();
				for (std::size_t i = 0; i < _size; ++i)
					_ptr[i] = cpy._ptr[i];
			}
			else
			{
				_ptr = NULL;
			}
		}
		return *this;
	}

	~Array(void)
	{
		delete[] _ptr;
	}

	// --- Element access ---
	T &operator[](std::size_t i)
	{
		if (i >= _size)
			throw std::out_of_range("Index out of bounds");
		return _ptr[i];
	}

	const T &operator[](std::size_t i) const
	{
		if (i >= _size)
			throw std::out_of_range("Index out of bounds");
		return _ptr[i];
	}

	// --- Size ---
	std::size_t size(void) const
	{
		return _size;
	}
};
