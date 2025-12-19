#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        ~RPN();

    void calcul(const std::string& expression);
};

#endif