#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void f()
{
    system("leaks Intern");
}
int main()
{
    atexit(f);
    srand(time(NULL));
    std::cout << "\n-----Testing with Default Constructor!-----\n" << std::endl;
    {
        std::cout << "\n-------------1st Form----------------\n" << std::endl;
        try
        {
            Bureaucrat v;
            PresidentialPardonForm d;
            Intern RaysStagir;
            AForm *tanga;
            tanga = RaysStagir.makeForm("presidential pardon", "chfar");
            v.signForm(d);
            v.executeForm(d);
            std::cout << d << std::endl;
            std::cout << v << std::endl;
            delete tanga;
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
            Intern www;
            AForm *ccc;
            ccc = www.makeForm("robotomy request", "Bender");
            d.signForm(z);
            d.executeForm(z);
            std::cout << d << std::endl;
            std::cout << z << std::endl;
            delete ccc;
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
            Intern test;
            AForm *Paper;
            Paper = test.makeForm("awdawzd", "tree");
            w.signForm(q);
            w.executeForm(q);
            std::cout << w << std::endl;
            std::cout << q << std::endl;
            delete Paper;
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
            Intern worker;
            AForm *release;
            release = worker.makeForm("awdawdawdsdw", "chfar");
            v.signForm(f);
            v.executeForm(f);
            std::cout << f << std::endl;
            std::cout << v << std::endl;
            delete release;
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
            Intern exWorker;
            AForm *recu;
            recu = exWorker.makeForm("robotomy request", "Marvin");
            d.signForm(r);
            d.executeForm(r);
            std::cout << d << std::endl;
            std::cout << r << std::endl;
            delete recu;
        }
        catch (std::exception &w)
        {
            std::cout << "2nd Exception Caught: " << w.what() << std::endl;
        }
        std::cout << "\n-------------3rd Form----------------\n" << std::endl;
        try
        {
            Bureaucrat z("flah", 140);
            ShrubberyCreationForm s("firma");
            Intern khdam;
            AForm *contract;
            contract = khdam.makeForm("testtest", "lozin");
            z.signForm(s);
            z.executeForm(s);
            std::cout << s << std::endl;
            std::cout << z << std::endl;
            delete  contract;
        }
        catch (std::exception &w)
        {
            std::cout << "3rd Exception Caught: " << w.what() << std::endl;
        }
    }
    return 0;
}
