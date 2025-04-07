/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:32:45 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/07 18:32:47 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class Data
{
    private:
        std::string _str;
    public:
        Data();
        Data(std::string &str);
        Data(const Data &src);
        ~Data();
        Data &operator=(const Data &src);
};
