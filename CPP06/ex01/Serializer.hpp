#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int num;
    std::string type;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& content);
        ~Serializer();
    public:
        static Data* deserialize(uintptr_t raw);
        static uintptr_t serialize(Data* ptr);
};

#endif