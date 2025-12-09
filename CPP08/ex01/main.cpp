#include "Span.hpp"

int main()
{
    Span sp(5);
    try 
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n---- MASSIVE TEST (10K num) ----\n";
    {
        Span spinix(10000);

        for (int i = 0; i < 10000; i++)
            spinix.addNumber(rand());

        std::cout << "Shortest span: " << spinix.shortestSpan() << std::endl;
        std::cout << "Longest span : " << spinix.longestSpan() << std::endl;
    }

    std::cout << "\n---- ITERATORS TEST ----\n";
    {
        std::vector<int> v;
        for (int i = 0; i < 100; i++)
            v.push_back(i * 2);

        Span sp(200);
        sp.addNumber(v.begin(), v.end());

        std::cout << "Iterators test shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Iterators test longest span : " << sp.longestSpan() << std::endl;
    }
    return 0;
}