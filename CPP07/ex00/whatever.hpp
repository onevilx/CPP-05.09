#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename type>
void swap(type &x, type &y)
{
    type tempo;
    tempo = x;
    x  = y;
    y = tempo;
}

template <typename type>
type min(const type &x, const type &y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template <typename type>
type max(const type &x, const type &y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

#endif