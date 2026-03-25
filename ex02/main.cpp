/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:21:42 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/25 11:21:43 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void testShrubbery()
{
	std::cout << "\n--- Shrubbery test ---" << std::endl;
	Bureaucrat bob("Bob", 130);
	ShrubberyCreationForm shrub("home");

	bob.signForm(shrub);
	bob.executeForm(shrub);
}

static void testRobotomy()
{
	std::cout << "\n--- Robotomy test ---" << std::endl;
	Bureaucrat alice("Alice", 40);
	RobotomyRequestForm robot("Bender");

	alice.signForm(robot);
	alice.executeForm(robot);
	alice.executeForm(robot);
}

static void testPresidential()
{
	std::cout << "\n--- Presidential test ---" << std::endl;
	Bureaucrat president("President", 1);
	PresidentialPardonForm pardon("Arthur Dent");

	president.signForm(pardon);
	president.executeForm(pardon);
}

static void testFailures()
{
	std::cout << "\n--- Failure test ---" << std::endl;
	Bureaucrat low("Low", 150);
	ShrubberyCreationForm shrub("garden");

	// Should fail because the form is not signed.
	low.executeForm(shrub);

	// Should fail because grade is too low to sign.
	low.signForm(shrub);
}

int main()
{
	try
	{
		testShrubbery();
		testRobotomy();
		testPresidential();
		testFailures();
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
	return 0;
}

