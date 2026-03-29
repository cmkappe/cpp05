/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:30:17 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/29 15:33:11 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}




/* Since filling out forms all day would be too cruel for our bureaucrats, 
interns exist to take on this tedious task. In this exercise, you must implement the Intern class. 
The intern has no name, no grade, and no unique characteristics. 
The only thing bureaucrats care about is that they do their job.
However, the intern has one key ability: the makeForm() function. 
This function takes two strings as parameters: the first one represents the name of a form, and the second one represents the target of the form. 
It returns a pointer to a AForm object (corresponding to the form name passed as a parameter), with its target initialized to the second parameter.
It should print something like:
   Intern creates <form>
If the provided form name does not exist, print an explicit error message. */
