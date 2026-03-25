/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:42:32 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/23 18:05:20 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 20);
        Bureaucrat bob("Bob", 140);

        Form taxForm("Tax Form", 100, 90);
        Form topSecret("Top Secret", 10, 5);

        std::cout << taxForm << std::endl;
        std::cout << topSecret << std::endl;

        alice.signForm(taxForm);
        bob.signForm(topSecret);
        alice.signForm(topSecret);

        std::cout << taxForm << std::endl;
        std::cout << topSecret << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form invalidHigh("Invalid High", 0, 42);
        std::cout << invalidHigh << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form invalidLow("Invalid Low", 42, 151);
        std::cout << invalidLow << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}