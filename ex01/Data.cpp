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

Data::Data() : _str("Default")
{}

Data::Data(std::string &str) : _str(str)
{}

Data::Data(const Data &src) : _str(src._str)
{}

Data::~Data()
{}

Data &Data::operator=(const Data &src)
{
    if (this != &src)
        this->_str = src._str;
    return (*this);
}
