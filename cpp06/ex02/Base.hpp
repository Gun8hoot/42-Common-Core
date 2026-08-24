
#pragma once

class	Base
{
	public:
		virtual ~Base(void) = 0;
		Base	*generate(void);
		void	identify(Base *p);
		void	identify(Base &p);
};
