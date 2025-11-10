#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& content)
{
    if (this != &content)
        target = content.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return ("failed to create or write to the file.");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);
    std::ofstream outFile(target + "_shrubbery");
    if (!outFile.is_open())
        throw FileCreationException();
    outFile << "        ###\n"
            << "       #o###\n"
            << "     #####o###\n"
            << "    #o#\\#|#/###\n"
            << "     ###\\|/#o#\n"
            << "      # }|{  #\n"
            << "        }|{\n";
    outFile.close();

    std::cout << "file has been created under the name: "<< target << "_shrubbery !" << std::endl;
}