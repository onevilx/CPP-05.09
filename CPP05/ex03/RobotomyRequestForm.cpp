#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm:: RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& content)
{
    if (this != &content)
        target = content.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char* RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
    return ("Robotomy failed!");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);

    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        throw RobotomyFailedException();   
}