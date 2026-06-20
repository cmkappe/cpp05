/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:21:42 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/29 15:48:03 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <memory>

static void testInternForm(const std::string& formName,
	const std::string& target, Bureaucrat& signer) {
	Intern intern;
	// makeForm allocates with new; unique_ptr guarantees cleanup on all paths
	std::unique_ptr<AForm> form(intern.makeForm(formName, target));

	// Unknown form names return NULL in Intern::makeForm
	if (!form)
		return;

	// Happy path: inspect, sign, then execute the created form
	std::cout << *form << std::endl;
	signer.signForm(*form);
	signer.executeForm(*form);
}

int main() {
	try
	{
		Bureaucrat chief("Chief", 1);

		std::cout << "\n--- Intern valid forms ---" << std::endl;
		testInternForm("shrubbery creation", "home", chief);
		testInternForm("robotomy request", "Bender", chief);
		testInternForm("presidential pardon", "Arthur Dent", chief);

		std::cout << "\n--- Intern invalid form ---" << std::endl;
		testInternForm("coffee request", "Office", chief);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}

