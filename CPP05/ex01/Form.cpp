#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), issigned(false), signgrade(150), signexe(150) 
{
    if (signgrade < 1 || signexe < 1)
        throw GradeTooHighException();
    if (signgrade > 150 || signexe > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string& _name, int gradeToSign, int gradeToExecute) : name(_name), issigned(false), signgrade(gradeToSign), signexe(gradeToExecute)
{
    if (signgrade < 1 || signexe < 1)
        throw GradeTooHighException();
    if (signgrade > 150 || signexe > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), issigned(obj.issigned), signgrade(obj.signgrade), signexe(obj.signexe) {}

Form& Form::operator=(const Form& content)
{
    if (this != &content)
        issigned = content.issigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return name;
}

bool    Form::getIsSigned() const
{
    return issigned;
}

int     Form::getGradeToSign() const
{
    return signgrade;
}

int     Form::getGradeToExecute() const
{
    return signexe;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > signgrade)
        throw GradeTooLowException();
    issigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too HIGH!");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too LOW!");
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
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
