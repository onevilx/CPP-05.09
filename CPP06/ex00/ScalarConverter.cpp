#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void) other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& content) { (void) content; return (*this); }

ScalarConverter::~ScalarConverter() {}


static bool TypeChar(const std::string& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool TypeInteger(const std::string& str)
{
    if (str == "+" || str == "-")
        return false;

    char    *final = NULL;
    std::strtol(str.c_str(), &final, 10);
    return (*final == '\0');
}

static bool TypeFloat(const std::string& str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;

    char *final = NULL;
    std::strtof(str.c_str(), &final);
    return (*final == 'f' && *(final + 1) == '\0');
}

static bool TypeDouble(const std::string& str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;

    char *final = NULL;
    std::strtod(str.c_str(), &final);
    return (*final == '\0');
}

static void printTypeChar(double w)
{
    std::cout << "char: ";

    if (std::isnan(w) || w < 0 || w > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(w)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(w) << "'" << std::endl;
}

static void printTypeInt(double w)
{
    std::cout << "int: ";

    if (std::isnan(w) || w > INT_MAX || w < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(w) << std::endl;
}

static void printTypeFloat(double w)
{
    std::cout << "float: ";
    float ff = static_cast<float>(w);

    if (std::isnan(ff) || std::isinf(ff))
        std::cout << ff << "f" << std::endl;
    else if (ff == static_cast<int>(ff))
        std::cout << std::fixed << std::setprecision(1) << ff << "f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(6) << ff << "f" << std::endl;
}

static void printTypeDouble(double w)
{
    std::cout << "double: ";

    if (std::isnan(w) || std::isinf(w))
        std::cout << w << std::endl;
    else if (w == static_cast<long long>(w))
        std::cout << std::fixed << std::setprecision(1) << w << std::endl;
    else
        std::cout << std::fixed << std::setprecision(6) << w << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    double value = 0.0;

    if (TypeChar(literal))
        value = static_cast<double>(literal[0]);
    else if (TypeInteger(literal))
        value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
    else if (TypeFloat(literal))
        value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    else if (TypeDouble(literal))
        value = (std::strtod(literal.c_str(), NULL));
    else
    {
        std::cout << "Invalid literal, try again!" << std::endl;
        return ;
    }

    printTypeChar(value);
    printTypeInt(value);
    printTypeFloat(value);
    printTypeDouble(value);
}