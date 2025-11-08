#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n-----Testing with Default Constructor!-----\n" << std::endl;
    {
        try
        {
            Bureaucrat v;
            Form d;
            v.signForm(d);
            std::cout << d << std::endl;
            std::cout << v << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "1st Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
        try
        {
            Bureaucrat d;
            d.decrementGrade();
            Form z;
            d.signForm(z);
            std::cout << d << std::endl;
            std::cout << z << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "2nd Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
        try
        {
            Bureaucrat z;
            z.incrementGrade();
            Form w;
            z.signForm(w);
            std::cout << w << std::endl;
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
            Bureaucrat v("Raysss", 10);
            Form f("contract mzra3a", 50, 22);
            v.decrementGrade();
            v.signForm(f);
            std::cout << f << std::endl;
            std::cout << v << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "1st Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
        try
        {
            Bureaucrat d("Youssef", 120);
            Form contract("hrga talyan", 70, 100);
            d.incrementGrade();
            d.signForm(contract);
            std::cout << d << std::endl;
            std::cout << contract << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "2nd Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
        try
        {
            Bureaucrat z("Mowatin", 3);
            Form tax("Dar Dariba", 2, 10);
            z.incrementGrade();
            z.signForm(tax);
            std::cout << tax << std::endl;
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
            Bureaucrat d("abdlhaak", 120);
            Bureaucrat v("Dazai", 6);
            Form contra("transcendence", 6, 10);
            d = v;
            v.decrementGrade();
            d.incrementGrade();
            d.signForm(contra);
            v.signForm(contra);
            std::cout << d << std::endl;
            std::cout << v << std::endl;
            std::cout << contra << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "1st Exception Caught: " << e.what() << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
        try
        {
            Bureaucrat d("hmstr", 1);
            Bureaucrat v("levi", 50);
            Form king("bogitooooo", 50, 25);
            d = v;
            d.signForm(king);
            v.signForm(king);
            std::cout << d << std::endl;
            std::cout << v << std::endl;
            std::cout << king << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "2nd Exception Caught: " << e.what() << std::endl;
        }
    }

    return 0;
}