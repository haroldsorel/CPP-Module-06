/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:11:58 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/03 18:12:00 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

double stringToDouble(std::string &str)
{
    return (std::stod(str));
}

float stringToFloat(std::string &str)
{
    str.pop_back();
    return (std::stof(str));
}

char stringToChar(std::string &str)
{
    return (str[0]);
}

int stringToInt(std::string &str)
{
    return (std::stoi(str));
}
