#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) 
{ 
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makePresidential(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeShrubbery(const std::string& target) 
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = 
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*creators[3])(const std::string& target) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    int i = 0;

    while (i < 3)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
        i++;
    }
    throw std::invalid_argument("Intern couldn't create the form: " + formName);
}
