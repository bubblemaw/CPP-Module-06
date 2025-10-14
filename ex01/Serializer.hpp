/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:28:38 by masase            #+#    #+#             */
/*   Updated: 2025/10/14 14:36:30 by masase           ###   ########.fr       */
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
    private:
        Serializer();
        Serializer(const Serializer  &obj);
        ~Serializer();
        const Serializer &operator=(const Serializer  &obj);
    public:
        static uintptr_t  serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif