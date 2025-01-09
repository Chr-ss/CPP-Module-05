/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/08 17:19:36 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << BLUE << "Bureaucrat default constructor called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << BLUE << "Bureaucrat constructor called." << RESET << std::endl;
}


{
	std::cout << BLUE << "Bureaucrat constructor called." << RESET << std::endl;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
{
	std::cout << BLUE << "Bureaucrat copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
	}
	std::cout << BLUE << "Bureaucrat copy assignment operator called." << RESET << std::endl;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called." << RESET << std::endl;
}
