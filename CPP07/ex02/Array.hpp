#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename Type>

class Array
{
    private:
        Type    *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();

        Array& operator=(const Array& content);
        Type& operator[](unsigned int i);
        const Type& operator[](unsigned int i) const;

        unsigned int size() const;

        class OutOfBounds : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#include "Array.tpp"

#endif