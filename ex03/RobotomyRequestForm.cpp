/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:42:24 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/29 15:09:35 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	(void)other;
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	static bool seeded = false;
	if (!seeded)
	{
		// Mix time with process id so quick repeated runs do not reuse one seed.
		std::srand(static_cast<unsigned int>(std::time(NULL))
			^ static_cast<unsigned int>(getpid()));
		seeded = true;
	}

	std::cout << "Bzzzzzz bzz... drilling noises..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed for " << target << std::endl;
}

