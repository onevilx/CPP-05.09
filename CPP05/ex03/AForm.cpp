#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default Form"), issigned(false), signgrade(150), signexe(150) 
{
    if (signgrade < 1 || signexe < 1)
        throw GradeTooHighException();
    if (signgrade > 150 || signexe > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string& _name, int gradeToSign, int gradeToExecute) : name(_name), issigned(false), signgrade(gradeToSign), signexe(gradeToExecute)
{
    if (signgrade < 1 || signexe < 1)
        throw GradeTooHighException();
    if (signgrade > 150 || signexe > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name), issigned(obj.issigned), signgrade(obj.signgrade), signexe(obj.signexe) {}

AForm& AForm::operator=(const AForm& content)
{
    if (this != &content)
        issigned = content.issigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return name;
}

bool    AForm::getIsSigned() const
{
    return issigned;
}

int     AForm::getGradeToSign() const
{
    return signgrade;
}

int     AForm::getGradeToExecute() const
{
    return signexe;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > signgrade)
        throw GradeTooLowException();
    issigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too HIGH!");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too LOW!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form cannot be executed because it is not signed.");
}

void AForm::checkExecution(const Bureaucrat &executor) const
{
    if (!issigned)
        throw FormNotSignedException();
    if (executor.getGrade() > signexe)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << obj.getName() << ", Signed: ";
    if (obj.getIsSigned())
        out << "Yes";
    else
        out << "No"; 
    out << ", Grade to Sign: " << obj.getGradeToSign()
        << ", Grade to Execute: " << obj.getGradeToExecute();
    return out;
}
