/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:03:19 by maw               #+#    #+#             */
/*   Updated: 2025/10/01 23:18:29 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::float_check(char *str, float *_float, int *valid_float)
{    
	errno = 0;
	char *pEnd;
	*_float = strtof(str, &pEnd);
	if ( pEnd == str || *pEnd != '\0')
	{    
		std::cout << "false float" << std::endl;
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

void ScalarConverter::int_check(char *str, int *_int, int *valid_int)
{    
	errno = 0;
	char *pEnd;
	*_int = strtol(str, &pEnd, 0);
	if ( pEnd == str || *pEnd != '\0')
	{    
		std::cout << "false long" << std::endl;
		*valid_int = impossible;
		return ;              
	}
	else if ((*_int == LONG_MIN || *_int == LONG_MAX) && errno == ERANGE)
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
		std::cout << "false double" << std::endl;
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
		std::cout << "ici" << std::endl;
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

void ScalarConverter::from_char_display(int **valid_tab, char *_char)
{
	std::cout <<  "char: ";
	if (*valid_tab[1] == impossible)
		std::cout << "impossible";
	else if (*valid_tab[1] == nondisp)
		std::cout << "Non displayable";		
	std::cout <<  "int: ";
	if (*valid_tab[0] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<int>(*_char) << std::endl;
	std::cout <<  "float: ";
	if (*valid_tab[2] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<float>(*_char) << std::endl;
	std::cout <<  "double: ";
	if (*valid_tab[3] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<double>(*_char) << std::endl;             
}

void ScalarConverter::from_double_display(int **valid_tab, double *_double)
{
	std::cout <<  "char: ";
	if (*valid_tab[1] == impossible)
		std::cout << "impossible";
	else if (*valid_tab[1] == nondisp)
		std::cout << "Non displayable";
	std::cout << static_cast<char>(*_double) << std::endl;		
	std::cout <<  "int: ";
	if (*valid_tab[0] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<int>(*_double) << std::endl;
	std::cout <<  "float: ";
	if (*valid_tab[2] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<float>(*_double) << std::endl;
	std::cout <<  "double: ";
	if (*valid_tab[3] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<double>(*_double) << std::endl;            
}

void ScalarConverter::from_float_display(int **valid_tab, float *_float)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout <<  "char: ";
	if (*valid_tab[1] == impossible)
		std::cout << "impossible";	
	else if (*valid_tab[1] == nondisp)
		std::cout << "Non displayable";
	std::cout << static_cast<char>(*_float) << std::endl;		
	std::cout <<  "int: ";
	if (*valid_tab[0] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<int>(*_float) << std::endl;
	std::cout <<  "float: ";
	if (*valid_tab[2] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<float>(*_float) << std::endl;
	std::cout <<  "double: ";
	if (*valid_tab[3] == impossible)
		std::cout << "impossible";
	std::cout << static_cast<double>(*_float) << std::endl;            
}

void ScalarConverter::from_int_display(int **valid_tab, int *_int)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	char _c = static_cast<char>(*_int);
	std::cout <<  "char: ";
	if (!isprint(_c))
		std::cout << "Non displayable" << std::endl;
	else	
		std::cout << _c << std::endl;		
	std::cout <<  "int: ";
	std::cout << static_cast<int>(*_int) << std::endl;
	std::cout <<  "float: ";
	std::cout << static_cast<float>(*_int) << std::endl;
	std::cout <<  "double: ";
	std::cout << static_cast<double>(*_int) << std::endl;			          
}

void ScalarConverter::convert(char *literal)
{
	int *valid_tab[4];
	int _int;
	char _char;
	float _float;
	double _double;
	int valid_int;
	int valid_char;
	int  valid_float;
	int  valid_double;
	valid_tab[0] = &valid_int;
	valid_tab[1] = &valid_char;
	valid_tab[2] = &valid_float;
	valid_tab[3] = &valid_double;			
	char_check(literal, &_char, valid_tab[1]);
	float_check(literal, &_float, valid_tab[2]);	
	double_check(literal, &_double, valid_tab[3]);
	int_check(literal, &_int, valid_tab[0]);	
	if (*valid_tab[1] == VALID)
	{
		std::cout << "display broo" << std::endl;
		from_char_display(valid_tab, &_char);
	}
	else if (valid_int == VALID)
		from_int_display(valid_tab, &_int);
	else if (valid_float == VALID)
		from_float_display(valid_tab, &_float);
	else if (valid_double == VALID)
		from_double_display(valid_tab, &_double);
}
