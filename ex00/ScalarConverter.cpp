/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:03:19 by maw               #+#    #+#             */
/*   Updated: 2025/10/14 14:42:55 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default ScalarConverter Constructor" <<  std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	std::cout << "Default ScalarConverter Copy Constructor" <<  std::endl;
	*this = obj;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Default ScalarConverter Destructor" <<  std::endl;
}

const ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	std::cout << "Default ScalarConverter Assignement operator" <<  std::endl;
	return *this;
}

void ScalarConverter::float_check(char *str, float *_float, int *valid_float)
{    
	errno = 0;
	char *pEnd;
	*_float = strtof(str, &pEnd);
	if (*pEnd == 'f')
	{
		str++;
		pEnd++;
	}
	if ( pEnd == str || *pEnd != '\0')
	{    
		*valid_float = impossible; 
		return ;   
	}
	else if ((*_float == LONG_MIN || *_float == LONG_MAX) && errno == ERANGE)
	{
		*valid_float = impossible;
		return ;
	}
	*valid_float = VALID;
}

void ScalarConverter::int_check(char *str, long int *_int, int *valid_int)
{    
	errno = 0;
	char *pEnd;
	
	*_int = strtol(str, &pEnd, 0);
	if ( pEnd == str || *pEnd != '\0')
	{    
		*valid_int = impossible;
		return ;              
	}
	else if ((*_int < INT_MIN || *_int > INT_MAX) && errno == ERANGE)
	{
		*valid_int = impossible;
		return ;        
	}
	*valid_int = VALID;	
}

void ScalarConverter::double_check(char *str, double *_double, int *valid_double)
{
	errno = 0;
	char *pEnd;
	*_double = strtod(str, &pEnd);
	if ( pEnd == str || *pEnd != '\0')
	{
		*valid_double = impossible;
		return ;		
	}
	else if ((*_double == LONG_MIN || *_double == LONG_MAX) && errno == ERANGE)
	{
		*valid_double = impossible;
		return ;		
	}
	*valid_double = VALID;
}

void ScalarConverter::char_check(char *str, char *_char, int *valid_char)
{
	int i = 0;
	if (isdigit(str[i]))
	{
		*valid_char = impossible;
		return ;		
	}
	if (!isprint(str[i]))
	{
		*valid_char = nondisp;
		return ;
	}
	while(str[i])
		i++;
	if (i > 1)
	{
		*valid_char = impossible;
		return ;
	}
	*_char = str[0];	
	*valid_char = VALID;	                        
}

void ScalarConverter::from_char_display(char *_char)
{
	double d = static_cast<double>(*_char);
	float f = static_cast<float>(*_char);
	long i = static_cast< long int>(*_char);
	std::cout <<  "char: ";	
	if (isprint(*_char))
		std::cout << *_char << std::endl;
	else
		std::cout << "Non displayable" << std::endl;		
	std::cout <<  "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << i << std::endl;
	std::cout <<  "float: ";
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << f << "f" << std::endl;
	std::cout <<  "double: ";
	if (d >  DBL_MAX || d < -DBL_MAX)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << d << std::endl;           
}

void ScalarConverter::from_double_display(double *_double)
{
	char c = static_cast<char>(*_double);
	float f = static_cast<float>(*_double);
	long i = static_cast< long int>(*_double);
	std::cout <<  "char: ";	
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;		
	std::cout <<  "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << i << std::endl;
	std::cout <<  "float: ";
	if (f > FLT_MAX || f < FLT_MIN)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << f << "f" << std::endl;
	std::cout <<  "double: ";
	if (*_double >  DBL_MAX || *_double < -DBL_MAX)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << *_double << std::endl;              
}

void ScalarConverter::from_float_display(float *_float)
{
	double d = static_cast<double>(*_float);
	char c = static_cast<char>(*_float);
	long i = static_cast< long int>(*_float);
	std::cout <<  "char: ";	
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;		
	std::cout <<  "int: ";
	if (i > INT_MAX || i < INT_MIN || isnan(*_float))
		std::cout << "impossible" << std::endl;
	else 
		std::cout << i << std::endl;
	std::cout <<  "float: ";
	if (*_float ==  INFINITY || *_float == -INFINITY)
		std::cout << *_float << "f" << std::endl;	
	else if (*_float > FLT_MAX || *_float < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << *_float << "f" << std::endl;		
	std::cout <<  "double: ";
	if (d ==  INFINITY || d == -INFINITY)
		std::cout << d << std::endl;	
	else if (d >  DBL_MAX || d < -DBL_MAX)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << d << std::endl;         
}

void ScalarConverter::from_int_display(long int *_int)
{
	double d = static_cast<double>(*_int);
	char c = static_cast<char>(*_int);
	float f = static_cast<float>(*_int);
	std::cout <<  "char: ";	
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;		
	std::cout <<  "int: ";
	if (*_int > INT_MAX || *_int < INT_MIN)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << *_int << std::endl;
	std::cout <<  "float: ";
	if (f ==  INFINITY || f == -INFINITY)
	{			
		std::cout << f << "f" << std::endl;	
	}
	else if (f > FLT_MAX || f < -FLT_MAX)
	{
		std::cout << "impossible" << std::endl;		
	}
	else 
		std::cout << f << "f" << std::endl;
	std::cout <<  "double: ";
	if (d ==  INFINITY || d == -INFINITY)
		std::cout << d << std::endl;	
	else if (d >  DBL_MAX || d < -DBL_MAX)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << d << std::endl;      
}

void display_impossible()
{
	std::cout <<  "char: impossible" << std::endl;
	std::cout <<  "int: impossible" << std::endl;
	std::cout <<  "float: impossible" << std::endl;
	std::cout <<  "double: impossible" << std::endl;			
}

void ScalarConverter::convert(char *literal)
{
	long int _int;
	char _char;
	float _float;
	double _double;
	int valid_int;
	int valid_char;
	int  valid_float;
	int  valid_double;		
	char_check(literal, &_char, &valid_char);
	float_check(literal, &_float, &valid_float);	
	double_check(literal, &_double, &valid_double);
	int_check(literal, &_int, &valid_int);	
	if (valid_char == VALID)
		from_char_display(&_char);
	else if (valid_int == VALID)		
		from_int_display(&_int);
	else if (valid_float == VALID)		
		from_float_display(&_float);		
	else if (valid_double == VALID)	
		from_double_display(&_double);
	else 
		display_impossible();
}
