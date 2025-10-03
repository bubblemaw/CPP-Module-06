/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:01:38 by maw               #+#    #+#             */
/*   Updated: 2025/10/01 22:15:01 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	ScalarConverter::convert("67");
	// ScalarConverter::convert("n");	
	// ScalarConverter::convert("nan");
	// ScalarConverter::convert("-inff");
	// ScalarConverter::convert("x");	
	return (0);
}

