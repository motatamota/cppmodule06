#include "ScalarConverter.h"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool	ScalarConverter::IsSpecial(const std::string &str)
{
	return (str == "nan" || str == "-inf" || str == "+inf");
}

//強固な数字排除

bool	ScalarConverter::IsLowerNum(const std::string &str)
{
	if (str == "f" || !str.size())
		return (true);
	if (str[0] != '.' || str.size() == 1 || (str.size() == 2 && str[1] == 'f'))
		return (false);
	for (size_t n = 1; n < str.size(); n++)
	{
		if (n != str.size() - 1 && (str[n] < '0' || str[n] > '9'))
			return (false);
	}
	if ((str[str.size() - 1] < '0' || str[str.size() - 1] > '9') && str[str.size() - 1] != 'f')
		return (false);
	return (true);
}

//floatの基底にのっとった数字排除
// bool	ScalarConverter::IsLowerNum(const std::string &str)
// {
// 	double		tmp;
// 	std::string	tmp2;

// 	std::stringstream ss(str);
// 	ss >> tmp;
// 	ss >> tmp2;
// 	std::cout << "test: " << tmp2 << std::endl;
// 	if ((tmp2.size() == 1 && tmp2[0] == 'f') || !tmp2.size())
// 		return (true);
// 	return (false);
// }

void ScalarConverter::OutputChar(const std::string &str)
{
	int		tmp;
	std::string	tmp2;
	char	c;

	std::cout << "char: ";
	if (IsSpecial(str))
		throw (ImpossibleException());
	//floatの基底にのっとった数字排除
	// if (!IsLowerNum(str))
	// 	throw (NotNumberException());
	std::stringstream ss(str);
	ss >> tmp;
	// 強
	ss >> tmp2;
	if (!IsLowerNum(tmp2))
		throw (NotNumberException());
	if (tmp > 126 || tmp < 32)
		throw (NonDisplayableException());
	std::cout << "'";
	c = static_cast<char>(tmp);
	std::cout << c;
	std::cout << "'" << std::endl;
}

void ScalarConverter::OutputInt(const std::string &str)
{
	int			tmp;
	std::string	tmp2;

	std::cout << "int: ";
	if (IsSpecial(str))
		throw (ImpossibleException());
	//floatの基底にのっとった数字排除
	// if (!IsLowerNum(str))
	// 	throw (NotNumberException());
	std::stringstream ss(str);
	ss >> tmp;
	// 強
	ss >> tmp2;
	if (!IsLowerNum(tmp2))
		throw (NotNumberException());
	std::cout << tmp << std::endl;
}

void ScalarConverter::OutputFloat(const std::string &str)
{
	float		ans;
	int			tmp;
	std::string	tmp2;

	std::cout << "float: ";
	if (IsSpecial(str))
	{
		std::cout << str << "f" << std::endl;
		return ;
	}
	std::stringstream ss(str);
	ss >> tmp;
	ss >> tmp2;
	if (!IsLowerNum(tmp2))
		throw (NotNumberException());
	std::stringstream(str) >> ans;
	if (std::fmod(ans, 1.0) == 0.0)
		std::cout << ans << ".0f" << std::endl;
	else
		std::cout << ans << "f" << std::endl;
}

void ScalarConverter::OutputDouble(const std::string &str)
{
	double		ans;
	int			tmp;
	std::string	tmp2;

	std::cout << "double: ";
	if (IsSpecial(str))
	{
		std::cout << str << std::endl;
		return ;
	}
	std::stringstream ss(str);
	ss >> tmp;
	ss >> tmp2;
	if (!IsLowerNum(tmp2))
		throw (NotNumberException());
	std::stringstream(str) >> ans;
	if (std::fmod(ans, 1.0) == 0.0)
		std::cout << ans << ".0" << std::endl;
	else
		std::cout << ans << std::endl;
}

void	ScalarConverter::convert(const std::string &str)
{
	try
	{
		OutputChar(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		OutputInt(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		OutputFloat(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		OutputDouble(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *ScalarConverter::NotNumberException::what() const throw()
{
	return ("not number");
}
