#include "F.h"

int	main()
{
	std::srand(std::time(0));
	Base *base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
}
