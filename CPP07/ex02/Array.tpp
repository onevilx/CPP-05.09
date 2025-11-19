#ifndef ARRAY_TPP
#define ARRAY_TPP


template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : array(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>::~Array() 
{
    delete [] array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& content)
{
    if (this != &content)
    {
        delete [] array;
        _size = content._size;
        array = new T[_size];
        unsigned int i = 0;
        while (i < _size)
        {
            array[i] = content.array[i];
            i++;
        }
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfBounds();
    return array[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfBounds();
    return array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
    return ("Array index is out of bounds!");
}

#endif