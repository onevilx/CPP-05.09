#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

class NotFoundException : public std::exception
{
    public:
        const char * what() const throw()
        {
            return ("Not found!");
        }
};

template <typename T>
typename T::iterator easyfind(T container, int val)
{
    typename T::iterator hh = std::find(container.begin(), container.end(), val);
    if (hh == container.end())
        throw NotFoundException();
    return hh;
}

#endif