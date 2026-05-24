/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:42:32 by ckappe            #+#    #+#             */
/*   Updated: 2026/05/24 18:05:55 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n=== Valid creation and grade changes ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
 
    
    std::cout << "\n\n=== Constructor boundary values ===" << std::endl;
    try
    {
        Bureaucrat highest("Highest", 1);
        Bureaucrat lowest("Lowest", 150);
        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== Invalid constructor values ===" << std::endl;
    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Grade 0 failed as expected: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Grade 151 failed as expected: " << e.what() << std::endl;
    }

    
    std::cout << "\n\n=== Increment and decrement limits ===" << std::endl;
    try
    {
        Bureaucrat top("Top", 1);
        top.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Increment at grade 1 failed as expected: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Decrement at grade 150 failed as expected: " << e.what() << std::endl;
    }

    
    std::cout << "\n\n=== Copy constructor and assignment ===" << std::endl;
    try
    {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Assigned", 100);
        assigned = original;
        std::cout << "original: " << original << std::endl;
        std::cout << "copy: " << copy << std::endl;
        std::cout << "assigned (name stays Assigned): " << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    return 0;
}