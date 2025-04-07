/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:28:43 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/07 18:28:44 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *dataPtr = new Data;
    uintptr_t intPtr;;

    std::cout << "Address of the Data object before serialization: " << dataPtr << std::endl;
    intPtr = Serializer::serialize(dataPtr);
    std::cout <<  "Address of the intermidiate uintptr pointer: " << intPtr << std::endl;
    Serializer::deserialize(intPtr);
    std::cout << "Address of the Data object after serialization: " << dataPtr << std::endl;
    return (0);
}

