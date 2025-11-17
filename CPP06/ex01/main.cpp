#include "Serializer.hpp"

int main()
{
    Data d;
    d.num = 23;
    d.type = "test";

    uintptr_t raw = Serializer::serialize(&d);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "the number is: " << ptr->num << " and the name is: " << ptr->type << std::endl;
}