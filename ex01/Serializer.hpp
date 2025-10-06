/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:28:38 by masase            #+#    #+#             */
/*   Updated: 2025/10/06 16:15:32 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>

struct Data
{
    int james = 007;
};

class Serializer
{
    public:
        static uintptr_t  serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif