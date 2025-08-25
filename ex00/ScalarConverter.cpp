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

    if (modff(f, &intpartf) == 0.0f && !std::isinf(f))
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

    if (modff(f, &intpartf) == 0.0f && !std::isinf(f))
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
    double input = stringToDouble(str);
    bool int_overflow = false;
    bool float_overflow = false;

    char   c = static_cast<char>(input);
    int    i = static_cast<int>(input);
    float  f = static_cast<float>(input);
    double d = input;

    if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
        int_overflow = true;
    if (!std::isinf(input) && (input > std::numeric_limits<float>::max() || input < -std::numeric_limits<float>::max()))
        float_overflow = true;
    if (std::isfinite(input) && int_overflow)
        std::cout << "char: impossible\n";
    else if (!std::isfinite(input) || i < 0 || i > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    if (std::isfinite(input) && int_overflow)
        std::cout << "int: impossible\n";
    else if (!std::isfinite(input))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << "\n";
    if (float_overflow)
        std::cout << "float: impossible\n";
    else if (std::floor(f) == f && !std::isinf(f))
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
    else
        std::cout << std::defaultfloat << std::setprecision(7) << "float: " << f << "f\n";
    if (std::floor(d) == d && !std::isinf(d))
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << "\n";
    else
        std::cout << std::defaultfloat << "double: " << d << "\n";
}


static void displayFromFloat(std::string str)
{
    float input = stringToFloat(str);
    bool int_overflow = false;

    char   c = static_cast<char>(input);
    int    i = static_cast<int>(input);
    float  f = input;
    double d = static_cast<double>(input);

    if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
        int_overflow = true;
    if (std::isfinite(input) && int_overflow)
        std::cout << "char: impossible\n";
    else if (!std::isfinite(input) || i < 0 || i > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    if (std::isfinite(input) && int_overflow)
        std::cout << "int: impossible\n";
    else if (!std::isfinite(input))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << "\n";
    if (std::floor(f) == f && !std::isinf(f))
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
    else
        std::cout << std::defaultfloat << std::setprecision(7) << "float: " << f << "f\n";
    if (std::floor(d) == d && !std::isinf(d))
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << "\n";
    else
        std::cout << std::defaultfloat << "double: " << d << "\n";
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
