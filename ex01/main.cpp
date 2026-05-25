/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:42:32 by ckappe            #+#    #+#             */
/*   Updated: 2026/05/24 18:59:43 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\n=== Form creation and << operator ===" << std::endl;
    try
    {
        Form taxForm("Tax Form", 100, 90);
        Form topSecret("Top Secret", 10, 5);
        std::cout << taxForm << std::endl;
        std::cout << topSecret << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Invalid form grades ===" << std::endl;
    try
    {
        Form invalidHigh("Invalid High", 0, 42);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Sign grade 0 failed as expected: " << e.what() << std::endl;
    }
    try
    {
        Form invalidLow("Invalid Low", 42, 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Execute grade 151 failed as expected: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Form boundary grades (1 and 150) ===" << std::endl;
    try
    {
        Form highestForm("Highest Form", 1, 1);
        Form lowestForm("Lowest Form", 150, 150);
        std::cout << highestForm << std::endl;
        std::cout << lowestForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Signing: sufficient grade ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 20);
        Form taxForm("Tax Form", 100, 90);
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Signing: insufficient grade ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 140);
        Form topSecret("Top Secret", 10, 5);
        bob.signForm(topSecret);
        std::cout << topSecret << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Signing: exact boundary (grade == required) ===" << std::endl;
    try
    {
        Bureaucrat exact("Exact", 50);
        Form form("Exact Form", 50, 50);
        exact.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Signing: one grade too low ===" << std::endl;
    try
    {
        Bureaucrat tooLow("Too Low", 51);
        Form form("Strict Form", 50, 50);
        tooLow.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Signing an already-signed form ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 20);
        Form form("Double Sign Form", 50, 50);
        alice.signForm(form);
        alice.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Form copy constructor and assignment ===" << std::endl;
    try
    {
        Form original("Original Form", 42, 42);
        Form copy(original);
        Form assigned("Assigned Form", 100, 100);
        assigned = original;
        std::cout << "original: " << original << std::endl;
        std::cout << "copy:     " << copy << std::endl;
        std::cout << "assigned (name stays Assigned Form): " << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    
    return 0;
}