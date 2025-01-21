#include "Serializer.h"

int	main()
{
	Data		data;
	Data		*ans;
	uintptr_t	sir;

	data.value = 42;
	data.name = "taiga";
	sir = Serializer::serialize(&data);
	std::cout << "name: " << data.name << std::endl;
	std::cout << "value: " << data.value << std::endl << std::endl;
	std::cout << "serial num: " << sir << std::endl;
	ans = Serializer::deserialize(sir);
	std::cout << "re name: " << ans->name << std::endl;
	std::cout << "re value: " << ans->value << std::endl << std::endl;
	ans->name = "no name";
	ans->value = 43;
	std::cout << "name: " << data.name << std::endl;
	std::cout << "value: " << data.value << std::endl << std::endl;
}
