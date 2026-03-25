#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), signedStatus(false), signGrade(150), executeGrade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : name(name), signedStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < highestGrade || executeGrade < highestGrade)
        throw GradeTooHighException();
    if (signGrade > lowestGrade || executeGrade > lowestGrade)
        throw GradeTooLowException();
    std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other)
        signedStatus = other.signedStatus;
    return *this;
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return signedStatus;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecuteGrade() const
{
    return executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    signedStatus = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!signedStatus)
        throw FormNotSignedException();
    if (executor.getGrade() > executeGrade)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Exception: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Exception: Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Exception: Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form \"" << form.getName() << "\""
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade()
       << ", execute grade: " << form.getExecuteGrade();
    return os;
}
