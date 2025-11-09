#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "\n-----Testing with Default Constructor!-----\n" << std::endl;
    {
        std::cout << "\n-------------1st Form----------------\n" << std::endl;
        try
        {
            Bureaucrat v;
            PresidentialPardonForm d;
            v.signForm(d);
            v.executeForm(d);
            std::cout << d << std::endl;
            std::cout << v << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "1st Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------2nd Form----------------\n" << std::endl;
        try
        {
            Bureaucrat d;
            RobotomyRequestForm z;
            d.signForm(z);
            d.executeForm(z);
            std::cout << d << std::endl;
            std::cout << z << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "2nd Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------3rd Form----------------\n" << std::endl;
        try
        {
            Bureaucrat w;
            ShrubberyCreationForm q;
            w.signForm(q);
            w.executeForm(q);
            std::cout << w << std::endl;
            std::cout << q << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "3rd Exception Caught: " << w.what() << std::endl;
        }
    }

    std::cout << "\n-----Testing with Parameterized Constructor!-----\n" << std::endl;
    {
        std::cout << "\n-------------1st Form----------------\n" << std::endl;
        try
        {
            Bureaucrat v("Raysss", 1);
            PresidentialPardonForm f("qbila");
            v.signForm(f);
            v.executeForm(f);
            std::cout << f << std::endl;
            std::cout << v << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "1st Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------2nd Form----------------\n" << std::endl;
        try
        {
            Bureaucrat d("Youssef", 6);
            RobotomyRequestForm r("robo factory");
            d.signForm(r);
            d.executeForm(r);
            std::cout << d << std::endl;
            std::cout << r << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "2nd Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------3rd Form----------------\n" << std::endl;
        try
        {
            Bureaucrat z("flah", 120);
            ShrubberyCreationForm s("firma");
            z.signForm(s);
            z.executeForm(s);
            std::cout << s << std::endl;
            std::cout << z << std::endl;
        }
        catch (std::exception &w)
        {
            std::cout << "3rd Exception Caught: " << w.what() << std::endl;
        }
    }

    std::cout << "\n-----Testing with Copy assignment operator!-----\n" << std::endl;
    {
        std::cout << "\n------------->TESTING<----------------\n" << std::endl;
        try
        {
            Bureaucrat d("hmstr", 1);
            Bureaucrat v("levi", 25);
            PresidentialPardonForm king("bogitooooo");

            d = v;
            d.signForm(king);
            v.signForm(king);
            d.executeForm(king);
            v.executeForm(king);
            std::cout << d << std::endl;
            std::cout << v << std::endl;
            std::cout << king << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Exception Caught: " << e.what() << std::endl;
        }
    }
    return 0;
}
