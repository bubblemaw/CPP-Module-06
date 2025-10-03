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

void ScalarConverter::convert(std::string literal)
{
    char *pEnd;
    const char *string = literal.c_str();
    int long c = strtol(string, &pEnd, 10);
    if ( c != 0L)
        std::cout << c << std::endl;
    else
        c = strtol(string, &pEnd, 10);     
    std::cout << c << std::endl;
    // try
    // {
    //     int c = strtol(string, &pEnd, 10);
    //     std::cout << "char: " << static_cast<char>(c) << std::endl;
    // }
    // catch (std::invalid_argument &e)
	// {
    //     std::cout << "char: " << "impossible" << std::endl;
    // }
    // try
    // {
    //     int num = stoi(literal);
    //     std::cout << "int: " << num << std::endl;
    // }
    // catch (std::invalid_argument &e)
	// {
    //     std::cout << "int: " << "impossible" << std::endl;
    // }
    // try
    // {
    //     float num = stof(literal);
    //     std::cout << "float: " << num << std::endl;
    // }
    // catch (std::invalid_argument &e)
	// {
    //     std::cout << "float: " << "impossible" << std::endl;
    // }
    // try
    // {
    //     double num = stod(literal);
    //     std::cout << "double: " << num << std::endl;
    // }
    // catch (std::invalid_argument &e)
	// {
    //     std::cout << "double: " << "impossible" << std::endl;
    // }    
}
