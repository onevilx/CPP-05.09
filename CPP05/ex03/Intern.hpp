#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
    public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& content);
    ~Intern();
    
    AForm *makeRobotomy(const std::string& target);
    AForm *makeShrubbery(const std::string& target);
    AForm *makePresidential(const std::string& target);
    AForm *makeForm(const std::string& formName, const std::string& target);

};

#endif