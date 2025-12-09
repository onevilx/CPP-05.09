#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _vec(other._vec) {}

Span::~Span() {}

Span& Span::operator=(const Span& content) 
{
    if (this != &content)
    {
        _N = content._N;
        _vec = content._vec;
    }
    return *this;
}

const char*  Span::SpanFullException::what() const throw()
{
    return ("Span is full, You can't add more numbers.");
}

const char*  Span::NoSpanException::what() const throw()
{
    return ("not enough numbers, try again!");
}

void Span::addNumber(int num)
{
    if (_vec.size() >= _N)
        throw SpanFullException();
    _vec.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();

    for (size_t i = 0; i < sorted.size() - 1; i++)
    {
        unsigned int diff = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_vec.size() < 2)
        throw NoSpanException();

    int minVal = *std::min_element(_vec.begin(), _vec.end());
    int maxVal = *std::max_element(_vec.begin(), _vec.end());

    return static_cast<unsigned int>(maxVal - minVal);
}