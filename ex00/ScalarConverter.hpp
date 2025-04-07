/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:15:59 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/03 17:16:01 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    ERROR
} ;

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);
        ScalarConverter(const ScalarConverter &src);
    public:
        static void convert(std::string const str);

};

double  stringToDouble(std::string &str);
int     stringToInt(std::string &str);
float   stringToFloat(std::string &str);
char    stringToChar(std::string &str);
e_type  detectType(std::string &str);

