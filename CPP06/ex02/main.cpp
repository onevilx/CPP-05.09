#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base* generate(void)
{
    int result = rand() % 3;

    switch (result)
    {
        case 0: return (new A());
        case 1: return (new B());
        case 2: return (new C());
        default:
            std::cout << "error in generate." << std::endl;
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type of cast" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...) {}
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...) {}
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...) {}
}

int main()
{
    std::srand(time(NULL));

    Base *ptr = generate();

    std::cout << "identify by pointer: ";
    identify(ptr);
    std::cout << "identify by reference: ";
    identify(*ptr);

    delete(ptr);
    return 0;
}