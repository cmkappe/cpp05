/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:21:42 by ckappe            #+#    #+#             */
/*   Updated: 2026/06/11 14:39:09 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void section(const std::string& title)
{
	std::cout << "\n\n=== " << title << " ===" << std::endl;
}

static void testExecuteUnsignedForm()
{
	section("Execute unsigned form should fail");
	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm shrub("unsigned_case");
	boss.executeForm(shrub);
}

static void testSignTooLow()
{
	section("Sign form with too-low grade should fail");
	Bureaucrat low("Low", 150);
	ShrubberyCreationForm shrub("low_sign_case");
	low.signForm(shrub);
}

static void testExecuteTooLow()
{
	section("Execute form with too-low grade should fail");
	Bureaucrat signer("Signer", 1);
	Bureaucrat executor("Executor", 140);
	ShrubberyCreationForm shrub("low_exec_case");
	signer.signForm(shrub);
	executor.executeForm(shrub);
}

static void testShrubberySuccess()
{
	section("Shrubbery success case");
	Bureaucrat gardener("Gardener", 130);
	ShrubberyCreationForm shrub("home");
	gardener.signForm(shrub);
	gardener.executeForm(shrub);
}

static void testRobotomySuccess()
{
	section("Robotomy success cases");
	Bureaucrat mechanic("Mechanic", 40);
	RobotomyRequestForm robot("wall-e");
	mechanic.signForm(robot);
	for (int i = 0; i < 6; ++i)
	{
		std::cout << "Attempt " << (i + 1) << ": ";
		mechanic.executeForm(robot);
	}
}

static void testPresidentialSuccess()
{
	section("Presidential success case");
	Bureaucrat president("President", 1);
	PresidentialPardonForm pardon("Arthur Dent");
	president.signForm(pardon);
	president.executeForm(pardon);
}

static void testPolymorphicExecution()
{
	section("Polymorphic execute through AForm reference");
	Bureaucrat chief("Chief", 1);
	RobotomyRequestForm robot("bender");
	// baseRef type is AForm&, but the real object is RobotomyRequestForm
	AForm& baseRef = robot;
	// using virtual will still run RobotomyRequestForm::executeAction
	chief.signForm(baseRef);
	chief.executeForm(baseRef);
}

int main()
{
	section("Initial form state print");
	ShrubberyCreationForm shrub("preview");
	RobotomyRequestForm robot("preview");
	PresidentialPardonForm pardon("preview");
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	testExecuteUnsignedForm();
	testSignTooLow();
	testExecuteTooLow();
	testShrubberySuccess();
	testRobotomySuccess();
	testPresidentialSuccess();
	testPolymorphicExecution();

	return 0;
}

