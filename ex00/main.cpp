/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:42:32 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/23 17:06:26 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        // This should throw an exception
        bob.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}