#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
    const std::string name;
    bool    issigned;
    const int signgrade;
    const int signexe;

    public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& obj);
    Form& operator=(const Form& content);
    ~Form();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);
    
    class GradeTooHighException : public std::exception
    {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif