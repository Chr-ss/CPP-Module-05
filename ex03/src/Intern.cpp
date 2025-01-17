/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/17 17:12:01 by crasche       ########   odam.nl         */
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
	AForm *(*allForms[])(const std::string &target) =
	{
		ShrubberyCreationForm::create,
		RobotomyRequestForm::create,
		PresidentialPardonForm::create
	};
	std::string formNames[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << BRIGHT_GREEN << "Intern creates \"" << formName << "\" form." << RESET << std::endl;
			return (allForms[i](target));
		}
	}
	std::cout << BRIGHT_RED << "Intern does not recognize the form name." << RESET << std::endl;
	return (NULL);
}