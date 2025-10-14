/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:18 by masase            #+#    #+#             */
/*   Updated: 2025/10/14 14:34:57 by masase           ###   ########.fr       */
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

	std::cout << sister->james << std::endl;
	return (0);
}