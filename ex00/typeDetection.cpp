/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeDetection.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:10:42 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/03 18:10:43 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(std::string &str)
{
    if (str.empty() == 1 || str.size() != 1 || (str[0] >= '0' && str[0] <= '9'))
        return (false);
    return (true);
}

static bool isInt(std::string const &str)
{
    size_t pos;

    if (str.empty() == true)
        return (false);
    try
    {
        int val = std::stoi(str, &pos);
        if (pos != str.length())
            return (false);
    }
    catch (const std::exception&) {return (false);}
    return (true);
}

static bool isFloat(const std::string &str)
{
    size_t pos;

    if (str.empty())
        return false;
    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return true;

    try
    {
        float   val = std::stof(str, &pos);
        if (!(pos == str.length() - 1 && str.back() == 'f'))
            return (false);
    }
    catch (const std::exception&) {return (false);}
    return (true);
}


static bool isDouble(std::string &str)
{
    size_t pos;

    if (str.empty() == 1)
        return (false);

    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        return (true);
    try
    {
        double val = std::stod(str, &pos);
        if (pos != str.length())
            return (false);
    }
    catch (const std::exception&) {return (false);}
    return (true);
}

e_type detectType(std::string &str)
{
    if (isChar(str) == true)
        return (CHAR);
    if (isInt(str) == true)
        return (INT);
    if (isDouble(str) == true)
        return (DOUBLE);
    if (isFloat(str) == true)
        return (FLOAT);
    return (ERROR);
}
