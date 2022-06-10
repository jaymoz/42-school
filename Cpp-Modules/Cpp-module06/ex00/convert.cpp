#include "main.hpp"

void convert_char(char *argv[])
{
    int         i;
    std::string s;

    s = argv[1];
    std::cout << "char: ";
    try
    {
        i = std::stoi(s);
        if (i< -128 || i > 127)
            std::cout << "impossible" << std::endl;
        else if (i < 32 || i > 126)
            std::cout << "not displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(i) << "'" <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }
}


void convert_int(char *argv[])
{
    int         i;
    std::string s;

    s = argv[1];
    std::cout << "int: ";
    try
    {
        i = std::stoi(s);
        std::cout << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }
}

void convert_float(char *argv[])
{
    std::string s;

    s = argv[1];
    float f;
    std::cout <<"float: ";
    try
    {
        f = std::stof(s);
        std::cout << f;
        if (!std::isnan(f) && !std::isinf(f) && f == std::floor(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }
}

void convert_double(char *argv[])
{
    std::string s;

    s = argv[1];
    double d;
    std::cout << "double: ";
    try
    {
        d = std::stod(s);
        std::cout << d;
        if (!std::isnan(d) && !std::isinf(d) && d == std::floor(d))
            std::cout << ".0";
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }
}

