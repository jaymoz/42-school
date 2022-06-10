#include "main.hpp"

int main(int argc, char  *argv[])
{
    if (argc == 2)
    {
        convert_char(argv);
        convert_int(argv);
        convert_float(argv);
        convert_double(argv);
    }
    else
    {
        std::cout << "Arguments must be 2"  << std::endl;
        return (1);
    }


    return (0);
}
