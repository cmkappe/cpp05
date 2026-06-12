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
        // Virtual destructor ensures correct derived destructor when deleting through AForm*
        virtual ~AForm();
        AForm& operator=(const AForm& other);

        const std::string& getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);
        // Non-virtual template method: shared checks live in base, action is delegated below
        void execute(Bureaucrat const& executor) const;

    protected:
        // Pure virtual makes AForm abstract: you cannot instantiate AForm directly
        // Virtual dispatch picks the derived class action at runtime
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
