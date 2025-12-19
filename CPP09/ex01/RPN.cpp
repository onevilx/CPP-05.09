#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

static bool isOperator(const std::string& ope)
{
    return (ope == "+" || ope == "-" || ope == "*" || ope == "/");
}

static int applyOperator(int a, int b, const std::string& op)
{
    if (op == "+") 
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: invalid operator");
}

void RPN::calcul(const std::string& expression)
{
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result = applyOperator(a, b, token);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error: invalid token");
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    std::cout << _stack.top() << std::endl;
}
