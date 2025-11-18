#ifndef ARRAY_TPP
#define ARRAY_TPP


template <typename type>
Array<type>::Array() : array(NULL), _size(0) {}

template <typename type>
Array<type>::Array(unsigned int n) : array(new type[array]), _size(n) {}

template <typename type>
Array<type>::Array(const Array& other) : array(new type[other.array]), _size(new type[other._size])
{
    *this = other;
}

template <typename type>
Array<type>::~Array() 
{
    delete [] array;
}

template <typename type>
Array<type>& Array<type>::operator=(const Array& content)
{
    
}

#endif