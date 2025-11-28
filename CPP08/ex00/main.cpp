#include "easyfind.hpp"

int main()
{
    std::cout << "-----> Testing with vector <-----" << std::endl;
    {
        int array[] = {2, 4, 6, 8, 10};
        std::vector<int> v(array, array + 5);
        try
        {
            std::vector<int>::iterator i =  easyfind(v, 10);
            std::cout << "L9iiitha YESSS! raha: " << *i << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "--------------" << std::endl;
        try
        {
            std::vector<int>::iterator i =  easyfind(v, 14);
            std::cout << "L9iiitha YESSS! raha: " << *i << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "-----> Testing with list<-----" << std::endl;
    {
        std::list<int> myListy;
        myListy.push_back(2);
        myListy.push_front(1);
        myListy.push_front(0);
        myListy.push_back(4);

        try
        {
            std::list<int>::iterator i =  easyfind(myListy, 2);
            std::cout << "L9iiitha YESSS! raha: " << *i << std::endl;
            for (std::list<int>::iterator fofo = myListy.begin(); fofo != myListy.end(); fofo++)
                std::cout << *fofo << " " << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "--------------" << std::endl;
        try
        {
            std::list<int>::iterator i =  easyfind(myListy, 3);
            std::cout << "L9iiitha YESSS! raha: " << *i << std::endl;
            for (std::list<int>::iterator fofo = myListy.begin(); fofo != myListy.end(); fofo++)
                std::cout << *fofo << " " << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}