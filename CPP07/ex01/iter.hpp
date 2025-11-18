#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename type_array,typename type_func>
void iter(type_array *array, size_t length, type_func function)
{
    size_t i = 0;
    while (i < length)
        function(array[i++]);
}

#endif