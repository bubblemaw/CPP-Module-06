/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:38:37 by masase            #+#    #+#             */
/*   Updated: 2025/10/14 14:36:38 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer()
{
    std::cout << "Serializer default constructor"<< std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
    std::cout << "Serializer copy constructor"<< std::endl;
    *this = obj;
}

Serializer::~Serializer()
{
    std::cout << "Serializer Destructor"<< std::endl;
}

const Serializer &Serializer::operator=(const Serializer &obj)
{
    std::cout << "Serializer assignement operator"<< std::endl;    
    if(this != &obj)
    {
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t result;
    result = reinterpret_cast<uintptr_t>(ptr);
    return (result);
}
Data* Serializer::deserialize(uintptr_t raw)
{
    Data *result;
    result = reinterpret_cast<Data*>(raw);
    return (result);
}