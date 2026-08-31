
# pragma once

template <typename T> void swap (T &a, T &b)
{
	T	save = b;

	b = a;
	a = save;
	return ;
}

template <typename T> T min (T &a, T &b)
{
	return ( a < b ? a : b );
}

template <typename T> T max (T &a, T &b)
{
	return ( a > b ? a : b );
}
