#include "iter.hpp"

void multiple_four(int &i)
{
    i *= 4;
}

void to_upper(std::string &str)
{
    size_t i = 0;
    while (i < str.length())
    {
        str[i] = std::toupper(str[i]);
        i++;
    }
}

int main(void)
{
    {
        std::cout << "----->let's test it with array<-----" << std::endl;
        int array[] = {1, 2, 3, 4, 5};
        ::iter(array, 5, multiple_four);
        int i = 0;
        while (i < 5)
            std::cout << array[i++] << std::endl;
    }
    {
        std::cout << "----->now testing with string<-----" << std::endl;
        std::string string_array[] = {"wafiin", "hanya", "salaaam"};
        ::iter(string_array, 3, to_upper);
        int i = 0;
        while (i < 3)
            std::cout << string_array[i++] << std::endl;
    }
        return 0;
}