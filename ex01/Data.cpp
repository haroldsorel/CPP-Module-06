/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:32:52 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/07 18:32:53 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _num(4242)
{}

Data::Data(int num) : _num(num)
{}

Data::Data(const Data &src) : _num(src._num)
{}

Data::~Data()
{}

int Data::getNum()
{
    return (this->_num);
}

Data &Data::operator=(const Data &src)
{
    if (this != &src)
        this->_num = src._num;
    return (*this);
}
