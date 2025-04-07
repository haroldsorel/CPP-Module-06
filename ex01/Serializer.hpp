/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:28:37 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/07 18:28:39 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &src);
        ~Serializer();
        Serializer &operator=(const Serializer &src);
    public:
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);
};

