/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:16:07 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/03 17:16:08 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    return (*this);
}

static void displayFromChar(std::string str)
{
    char input = stringToChar(str);

    char    c = static_cast<char>(input);
    int     i = static_cast<int>(input);
    float   f = static_cast<float>(input);
    double  d = static_cast<double>(input);
    float   intpartf;
    double  intpart;

    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;

    if (std::modff(f, &intpartf) == 0.0f && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::modf(f, &intpart) == 0.0 && !std::isinf(f))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void displayFromInt(std::string str)
{
    int input = stringToInt(str);

    char    c = static_cast<char>(input);
    int     i = static_cast<int>(input);
    float   f = static_cast<float>(input);
    double  d = static_cast<double>(input);
    float   intpartf;
    double  intpart;

    if (i > 127 || i < -128)
        std::cout << "char: impossible" << std::endl;
    else if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!(std::isprint(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;

    std::cout << "int: " << i << std::endl;

    if (std::modff(f, &intpartf) == 0.0f && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::modf(f, &intpart) == 0.0 && !std::isinf(f))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void displayFromDouble(std::string str)
{
    double  input = stringToDouble(str);
    int     int_overflow = false;
    int     float_overflow = false;

    char    c = static_cast<char>(input);
    int     i = static_cast<int>(input);
    float   f = static_cast<float>(input);
    double  d = static_cast<double>(input);
    float   intpartf;
    double  intpart;

    if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
        int_overflow = true;
    if (!std::isinf(input) && (input > std::numeric_limits<float>::max() || input < -std::numeric_limits<float>::max()))
        float_overflow = true;

    if (std::isfinite(input) && int_overflow)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isfinite(input) || i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!(std::isprint(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;

    if (std::isfinite(input) && int_overflow)
        std::cout << "int: impossible" << std::endl;
    else if (!(std::isfinite(input)))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (float_overflow == true)
        std::cout << "float: impossible" << std::endl;
    else if (std::modff(f, &intpartf) == 0.0f && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::modf(f, &intpart) == 0.0 && !std::isinf(f))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void displayFromFloat(std::string str)
{
    float input = stringToFloat(str);
    bool int_overflow = false;

    char    c = static_cast<char>(input);
    int     i = static_cast<int>(input);
    float   f = static_cast<float>(input);
    double  d = static_cast<double>(input);
    float   intpartf;
    double  intpart;

    if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
        int_overflow = true;

    if (std::isfinite(input) && int_overflow)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isfinite(input) || i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!(std::isprint(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;

    if (std::isfinite(input) && int_overflow)
        std::cout << "int: impossible" << std::endl;
    else if (!(std::isfinite(input)))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (std::modff(f, &intpartf) == 0.0f && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::modf(f, &intpart) == 0.0 && !std::isinf(f))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void displayFromError(std::string str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: imposible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    e_type type = detectType(str);

    std::cout << std::endl;
    std::cout << std::endl << "------------------------------" << std::endl;
    switch (type)
    {
        case CHAR:
            displayFromChar(str);
            break;
        case INT:
            displayFromInt(str);
            break;
        case DOUBLE:
            displayFromDouble(str);
            break;
        case FLOAT:
            displayFromFloat(str);
            break;
        case ERROR:
            displayFromError(str);
    }
    std::cout << "------------------------------" << std::endl << std::endl;

}
