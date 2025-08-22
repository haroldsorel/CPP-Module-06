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
        int _num;
    public:
        Data();
        Data(int num);
        Data(const Data &num);
        ~Data();
        int getNum();
        Data &operator=(const Data &num);
};
