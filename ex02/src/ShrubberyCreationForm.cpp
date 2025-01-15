/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/15 13:30:07 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << BLUE << "ShrubberyCreationForm default constructor called." << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << BLUE << "ShrubberyCreationForm target constructor called." << RESET << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy), _target(toCopy._target)
{
	std::cout << BLUE << "ShrubberyCreationForm copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_target = other._target;
	std::cout << BLUE << "ShrubberyCreationForm copy assignment operator called. Unable to assign form values." << RESET << std::endl;
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called." << RESET << std::endl;
}

// Public functions
void	ShrubberyCreationForm::beSigned()
{
	AForm::beSigned();
	std::cout << BRIGHT_GREEN << "\""<< AForm::getName() << "\" has been signed." << RESET << std::endl;
}

void	ShrubberyCreationForm::executeForm(Bureaucrat const & executor) const
{
	if (executor.getGrade() > AForm::getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream file;
	file.open(AForm::getName() + "_shrubbery");
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file.close();
}
