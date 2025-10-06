/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:38:37 by masase            #+#    #+#             */
/*   Updated: 2025/10/06 16:15:32 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

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