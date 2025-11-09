#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    private:
    const std::string name;
    bool    issigned;
    const int signgrade;
    const int signexe;
    
    protected:
    void checkExecution(Bureaucrat const &executor) const;

    public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& obj);
    AForm& operator=(const AForm& content);
    virtual ~AForm();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    virtual void execute(Bureaucrat const & executor) const = 0;

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
    class FormNotSignedException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif