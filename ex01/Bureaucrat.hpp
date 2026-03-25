# pragma once

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Bureaucrat
{
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                // what() gives the error message text for this exception
                // `virtual`: lets C++ call the right version through std::exception
                // `const char*`: returns a C-style string (text)
                // `const`: calling this does not change the exception object
                // `throw()`: old C++98 way to say this function will not throw
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                // Same idea here: this returns the message for "grade too low"
                // Signature matches std::exception::what() so overriding works correctly
                virtual const char* what() const throw();
        };

        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void signForm(Form& form) const;
    
    private:
        const std::string name;
        int grade;
        static const int highestGrade = 1;
        static const int lowestGrade = 150;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b); 
