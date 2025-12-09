#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& content);
        ~Span();

        void addNumber();
        
};

#endif