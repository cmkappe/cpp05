/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:21:55 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/23 18:05:19 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name("default"), signedStatus(false), signGrade(150), executeGrade(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : name(name), signedStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < highestGrade || executeGrade < highestGrade)
        throw GradeTooHighException();
    if (signGrade > lowestGrade || executeGrade > lowestGrade)
        throw GradeTooLowException();
    std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(const Form& other)
    : name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // name, signGrade, and executeGrade are const, so we don't assign them
        signedStatus = other.signedStatus;
    }
    return *this;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signedStatus;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecuteGrade() const
{
    return executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    signedStatus = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Exception: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Exception: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form \"" << form.getName() << "\""
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade()
       << ", execute grade: " << form.getExecuteGrade();
    return os;
}
