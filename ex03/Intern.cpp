/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:30:17 by ckappe            #+#    #+#             */
/*   Updated: 2026/06/18 17:22:43 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	// Table-driven dispatch keeps the function short and avoids a long if/else chain.
	// Each row maps the subject's form name string to one factory function.
	typedef AForm* (*FormCreator)(const std::string&);
	struct FormEntry { const char* name; FormCreator create; };

	static const FormEntry table[] = {
		{ "shrubbery creation",
		  [](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); } },
		{ "robotomy request",
		  [](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); } },
		{ "presidential pardon",
		  [](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); } },
	};
	static const size_t tableSize = sizeof(table) / sizeof(*table);

	for (size_t i = 0; i < tableSize; ++i) {
		if (formName == table[i].name)
		{
			// Match found: announce it, then create the requested form on the heap.
			std::cout << "Intern creates " << formName << std::endl;
			return table[i].create(target);
		}
	}

	// Unknown form names must fail explicitly so the caller can handle nullptr.
	std::cerr << "Error: Unknown form name '" << formName << "'" << std::endl;
	return nullptr;
}
