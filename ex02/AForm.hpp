# pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        AForm();
        AForm(const std::string& name, int signGrade, int executeGrade);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);

        const std::string& getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const& executor) const;

    protected:
        virtual void executeAction() const = 0;

    private:
        const std::string name;
        bool signedStatus;
        const int signGrade;
        const int executeGrade;
        static const int highestGrade = 1;
        static const int lowestGrade = 150;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
