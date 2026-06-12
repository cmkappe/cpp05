/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:44:35 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/29 14:59:30 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Exception: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Exception: Grade too low";
}

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // name is const, so we don't assign it
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (grade < highestGrade)
        throw GradeTooHighException();
    if (grade > lowestGrade)
        throw GradeTooLowException();
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= highestGrade)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= lowestGrade)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
