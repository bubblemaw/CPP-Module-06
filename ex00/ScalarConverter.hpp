/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:10:03 by maw               #+#    #+#             */
/*   Updated: 2025/10/01 22:36:54 by maw              ###   ########.fr       */
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
# include <climits>

# define impossible 0
# define nondisp 1
# define VALID 2

class ScalarConverter
{
	private:
		// int _int;
		// char _char;
		// static float _float;
		// static double _double;
		// static int valid_int;
		// static int valid_char;
		// static int  valid_float;
		// static int  valid_double;		
	public:
		static void convert(char *literal);
		static void float_check(char *str, float *_float, int *valid_float);
		static void int_check(char *str, int *_int, int *valid_int);
		static void double_check(char *str, double *_double, int *valid_double);
		static void char_check(char *str, char *_char, int *valid_char);
		static void from_int_display(int **valid_tab, int *_int);
		static void from_double_display(int **valid_tab, double *_double);
		static void from_float_display(int **valid_tab, float *_float);
		static void from_char_display(int **valid_tab, char *_char);

};

#endif