#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n-----Testing with Default Constructor!-----\n" << std::endl;
    {
        try
        {
            Bureaucrat v;
            std::cout << v << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "1st Exception Caught: " << w.what() << std::endl;
        }
        try
        {
            Bureaucrat d;
            d.incrementGrade();
            std::cout << d << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "2nd Exception Caught: " << w.what() << std::endl;
        }
        try
        {
            Bureaucrat z;
            z.decrementGrade();
            std::cout << z << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "3rd Exception Caught: " << w.what() << std::endl;
        }
    }
    std::cout << "\n-----Testing with Parameterized Constructor!-----\n" << std::endl;
    {
        try
        {
            Bureaucrat v("Raysss", -1);
            v.incrementGrade();
            std::cout << v << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "1st Exception Caught: " << w.what() << std::endl;
        }
        try
        {
            Bureaucrat d("Youssef", 151);
            std::cout << d << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "2nd Exception Caught: " << w.what() << std::endl;
        }
        try
        {
            Bureaucrat z("Tester", 6);
            std::cout << z << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "3rd Exception Caught: " << w.what() << std::endl;
        }
    }
    std::cout << "\n-----Testing with Copy assignment operator!-----\n" << std::endl;
    {
        try
        {
            Bureaucrat d("Tester_1", 120);
            Bureaucrat v("Tester_2", 1);
            d = v;
            v.decrementGrade();
            d.incrementGrade();
            std::cout << d << std::endl;
            std::cout << v << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "1st Exception Caught: " << e.what() << std::endl;
        }
        try
        {
            Bureaucrat d("Skinnyyyy", 150);
            Bureaucrat v("Dazaaaiii", 60);
            d = v;
            v.decrementGrade();
            d.incrementGrade();
            std::cout << d << std::endl;
            std::cout << v << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "2nd Exception Caught: " << e.what() << std::endl;
        }
    }

    return 0;
}