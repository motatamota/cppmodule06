#ifndef SE_H
# define SE_H
# include <iostream>
# include <cstdint>
# include <string>

typedef struct s_data
{
	int			value;
	std::string	name;
} Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);

public:
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
