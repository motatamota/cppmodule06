#ifndef F_H
# define F_H
# include "Base.h"
# include "A.h"
# include "B.h"
# include "C.h"
# include <iostream>
# include <cstdlib>
# include <ctime>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
