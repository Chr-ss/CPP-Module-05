/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/15 14:35:05 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

// Constructor
Intern::Intern()
{
	std::cout << BLUE << "Intern default constructor called." << RESET << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &toCopy)
{
	(void)toCopy;
	std::cout << BLUE << "Intern copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << BLUE << "Intern copy assignment operator called." << RESET << std::endl;
	return (*this);
}

// Destructor
Intern::~Intern()
{
	std::cout << RED << "Intern destructor called." << RESET << std::endl;
}

// Public functions
AForm*	Intern::makeForm(std::string formName, std::string target)
{
	if (formName == "shrubbery creation")
	{
		std::cout << BRIGHT_GREEN << "Intern creates \"" << formName << "\" form." << RESET << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (formName == "robotomy request")
	{
		std::cout << BRIGHT_GREEN << "Intern creates \"" << formName << "\" form." << RESET << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (formName == "presidential pardon")
	{
		std::cout << BRIGHT_GREEN << "Intern creates \"" << formName << "\" form." << RESET << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << BRIGHT_RED << "Intern does not recognize the form name." << RESET << std::endl;
		return (NULL);
	}
}