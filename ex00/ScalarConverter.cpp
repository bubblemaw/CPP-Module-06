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

bool float_converter(char *str, float *c)
{
    errno = 0;
    char *pEnd;
    *c = strtof(str, &pEnd);
    if ( pEnd == str || *pEnd != '\0')
    {    
        std::cout << "false float" << std::endl;
        return false;
    }
    else if ((*c == LONG_MIN || *c == LONG_MAX) && errno == ERANGE)
        return false;
    return true;
}

bool long_converter(char *str, long int *c)
{
    errno = 0;
    char *pEnd;
    *c = strtol(str, &pEnd, 0);
    if ( pEnd == str || *pEnd != '\0')
    {    
        std::cout << "false long" << std::endl;
        return false;
    }
    else if ((*c == LONG_MIN || *c == LONG_MAX) && errno == ERANGE)
        return false;
    return true;
}

bool double_converter(char *str, double *c)
{
    errno = 0;
    char *pEnd;
    *c = strtod(str, &pEnd);
    if ( pEnd == str || *pEnd != '\0')
    {
        std::cout << "false double" << std::endl;
        return false;
    }
    else if ((*c == LONG_MIN || *c == LONG_MAX) && errno == ERANGE)
        return false;
    return true;
}

bool char_check(char *str)
{
    int i = 0;

    if (isdigit(str[i]))
        return (false);
    if (!isprint(str[i]))
        return (false);        
    while(str[i])
        i++;
    if (i > 1)
        return (false);
    return (true);                                 
}

void display_convert_long(long int *num)
{
    std::cout << "char: " << char(*num) << std::endl;
    std::cout << "int: " << int(*num) << std::endl;
    std::cout << "float: " << float(*num) << std::endl;
    std::cout << "double: " << double(*num) << std::endl;            
}

void display_convert_double(double *num)
{
    std::cout << "char: " << static_cast<char>(*num) << std::endl;
    std::cout << "int: " << static_cast<int>(*num) << std::endl;
    std::cout << "float: " << static_cast<float>(*num) << std::endl;
    std::cout << "double: " << static_cast<double>(*num) << std::endl;            
}

void display_convert_float(float *num)
{
    std::cout << "char: " << static_cast<char>(*num) << std::endl;
    std::cout << "int: " << static_cast<int>(*num) << std::endl;
    std::cout << "float: " << static_cast<float>(*num) << std::endl;
    std::cout << "double: " << static_cast<double>(*num) << std::endl;            
}

void display_convert_char(char c)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << int(c) << std::endl;
    std::cout << "float: " << float(c) << std::endl;
    std::cout << "double: " << double(c) << std::endl;            
}



void ScalarConverter::convert(char *literal)
{
    double n_double = 0;
    long int n_long = 0;
    float n_float = 0;
    if (char_check(literal))
        display_convert_char(literal[0]);
    else if (long_converter(literal, &n_long))
        display_convert_long(&n_long);
    else if (double_converter(literal, &n_double))
        display_convert_double(&n_double);
    else if (float_converter(literal, &n_float))
        display_convert_float(&n_float);                
}
