/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:10:03 by maw               #+#    #+#             */
/*   Updated: 2025/10/12 13:19:01 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <ostream>
# include <math.h>
# include <sstream>
# include <exception>
# include <stdlib.h>
# include <float.h>
# include <climits>

# define impossible 0
# define nondisp 1
# define VALID 2

class ScalarConverter
{
	private:	
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		~ScalarConverter();
		const ScalarConverter& operator=(const ScalarConverter &obj);
		static void convert(char *literal);
		static void float_check(char *str, float *_float, int *valid_float);
		static void int_check(char *str, long int *_int, int *valid_int);
		static void double_check(char *str, double *_double, int *valid_double);
		static void char_check(char *str, char *_char, int *valid_char);
		static void from_int_display(long int *_int);
		static void from_double_display(double *_double);
		static void from_float_display(float *_float);
		static void from_char_display(char *_char);
		virtual void tokoss() = 0;

};

#endif