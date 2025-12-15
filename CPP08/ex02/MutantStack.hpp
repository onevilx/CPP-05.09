#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>
#include <iostream>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef std::stack<T, Container>                    base_type;
        typedef typename base_type::container_type          container_type;

        typedef typename container_type::iterator           iterator;
        typedef typename container_type::const_iterator     const_iterator;

    MutantStack() : base_type() {}
    MutantStack(const MutantStack& other) : base_type(other) {}
    MutantStack& operator=(const MutantStack& content)
    {
        if (this != &content)
            base_type::operator=(content);
        return *this;
    }
    ~MutantStack() {}

    iterator begin()              { return this->c.begin(); }
    iterator end()                { return this->c.end(); }
    const_iterator begin() const              { return this->c.begin(); }
    const_iterator end()   const              { return this->c.end(); }
};

#endif
