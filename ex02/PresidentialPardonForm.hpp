# pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    protected:
        virtual void executeAction() const;
    
    private:
        const std::string target;
};
