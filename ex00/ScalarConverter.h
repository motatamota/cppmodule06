#ifndef SCCON_H
# define SCCON_H
# include <string>
# include <iostream>
# include <sstream>
# include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	static bool IsSpecial(const std::string &str);
	static void	OutputChar(const std::string &str);
	static void	OutputInt(const std::string &str);
	static void	OutputFloat(const std::string &str);
	static void	OutputDouble(const std::string &str);
	static bool	IsLowerNum(const std::string &str);

public:
	~ScalarConverter();

	static void	convert(const std::string &str);
	class NonDisplayableException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ImpossibleException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class NotNumberException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
