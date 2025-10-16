/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:18 by masase            #+#    #+#             */
/*   Updated: 2025/10/16 13:54:28 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data bro;
	Data *sister;
	uintptr_t gluck;

	gluck = Serializer::serialize(&bro);
	sister = Serializer::deserialize(gluck);

	std::cout << "* VALUEEEEE *" << std::endl;
	std::cout << bro.james << std::endl;
	std::cout << sister->james << std::endl;

	std::cout << "* ADDRESS *" << std::endl;
	std::cout << &bro.james << std::endl;
	std::cout << &sister->james << std::endl;

	return (0);
}