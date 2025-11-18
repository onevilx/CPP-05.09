#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
    private:
        T    *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();

        Array& operator=(const Array& content);
        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;

        unsigned int size() const;

        class OutOfBounds : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#include "Array.tpp"

#endif