/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/15 13:31:24 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << BLUE << "PresidentialPardonForm default constructor called." << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << BLUE << "PresidentialPardonForm target constructor called." << RESET << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm(toCopy), _target(toCopy._target)
{
	std::cout << BLUE << "PresidentialPardonForm copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		_target = other._target;
	std::cout << BLUE << "PresidentialPardonForm copy assignment operator called. Unable to assign form values." << RESET << std::endl;
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called." << RESET << std::endl;
}

// Public functions
void	PresidentialPardonForm::beSigned()
{
	AForm::beSigned();
	std::cout << BRIGHT_GREEN << "\"" << AForm::getName() << "\" on target \"" << _target << "\", has been signed." << RESET << std::endl;
}

void	PresidentialPardonForm::executeForm(Bureaucrat const & executor) const
{
	if (executor.getGrade() > AForm::getExecuteGrade())
		throw GradeTooLowException();
	std::cout << BOLD << BRIGHT_GREEN << "\""<< _target << "\" has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
