# pragma once

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat
{
    public:
        
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);
        
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
        // virtual means "check the real type at runtime, not the declared type at compile time"
        // without virtual: always calls std::exception::what() → empty/useless message
        // with virtual: calls exception override → "Exception: Grade too high"

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
    
    private:
        const std::string name;
        int grade;
        static const int highestGrade = 1;
        static const int lowestGrade = 150;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b); 
