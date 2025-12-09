#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& content);
        ~Span();

        void addNumber(int num);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        template <typename Ite>
        void addNumber(Ite begin, Ite end)
        {
            for (Ite it = begin; it != end; ++it)
            {
                if (_vec.size() >= _N)
                    throw SpanFullException();
                _vec.push_back(*it);
            }
        }

    class SpanFullException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

};

#endif