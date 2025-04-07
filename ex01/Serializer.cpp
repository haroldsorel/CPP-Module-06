/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:28:31 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/07 18:28:33 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &src)
{}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=(const Serializer &src)
{
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
    return (addr); 
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *addr = reinterpret_cast<Data*>(raw);
    return (addr);
}
