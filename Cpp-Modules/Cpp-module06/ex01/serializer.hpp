#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <cstring>

typedef struct s_Data
{
    int test1;
    float test2;
    char value3;
    std::string test4;

} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif