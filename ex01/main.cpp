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

/*
    Adresses are bits in memory ex :
    Binary Form : 0000 0111 1111 1111 1110 1110 1001 1010 0011 1100 0010 0001 0000
    However this is not very human readable so let's put it in decimal format:
    Decimal Form : 140732765580560
    Better but this is hard to go back to binary form and vice-versa soooo let's use a practical base
    Hexadecimal Form : 0x7FFEE9A3C210

    Decimal numbers are human readable but since computers use bits (base 2) using decimals makes no sense
    So we chose to use Hexadecimals to bridge the gap between binary and decimal so its compact enough and 
    makes patterns appear in memory because data types are powers of 2 so it's easy for debugging ect...

    The point of this exercice is to understand pointer type casting and is only possible via reinterpret cast.
    which means "Take these bits and treat them as something else, without changing them."

    Why uintptr? this data type can safely store any memory adresse. it is architecture based so the memory adress
    will never be truncated and therefore will remain true to the pointed object.

    So we start with a pointer to a Data Object and store that memory adress as an integer using reinterpret cast and then
    we cast that integer back to Data and it should still point to the Data Object.
*/

int main()
{
    Data data(4242);
    Data *dataPtr = &data;
    uintptr_t intPtr; //change this to int to show truncation and segfault or garbage value

    std::cout << "Address of the Data object: " << dataPtr << std::endl;
    std::cout << "Data object data: " << (*dataPtr).getNum() << std::endl;

    intPtr = Serializer::serialize(dataPtr);
    //intPtr++; //to change address. this will make it point to a radom thing when deserializing or segfaulting
    
    std::cout <<  "Raw adress of Data object in integers : " << intPtr << std::endl;

    //Pointing to null to see if i kept the correct adress
    dataPtr = nullptr;

    //Getting back the address of Data object from the uintptr
    dataPtr = Serializer::deserialize(intPtr);

    std::cout << "Address of the Data object: " << dataPtr << std::endl;
    std::cout << "Data object data: " << (*dataPtr).getNum() << std::endl;

    /* What if i use something else then uintptr? something that can't hold a full memory adress -> truncation*/
    return (0);
}

