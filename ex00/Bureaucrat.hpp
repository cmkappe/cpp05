# pragma once

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat
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

        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);

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
