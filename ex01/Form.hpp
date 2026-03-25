# pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
    public:

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        Form();
        Form(const std::string& name, int signGrade, int executeGrade);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        const std::string& getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);

    private:
        const std::string name;
        bool signedStatus;
        const int signGrade;
        const int executeGrade;
        static const int highestGrade = 1;
        static const int lowestGrade = 150;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

/* Let’s create a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.
All these attributes are private, not protected.
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
As before, write getters for all attributes and overload the insertion («) operator to
print all the form’s information. */