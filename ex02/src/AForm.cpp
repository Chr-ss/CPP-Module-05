/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/15 09:29:47 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

// Constructor
AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << BLUE << "AForm default constructor called." << RESET << std::endl;
}
AForm::AForm(std::string name) : _name(name), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << BLUE << "AForm name constructor called." << RESET << std::endl;
}
AForm::AForm(unsigned int signGrade, unsigned int executeGrade) : _name("default"), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
	if (executeGrade < 1)
		throw GradeTooHighException();
	else if (executeGrade > 150)
		throw GradeTooLowException();
	std::cout << BLUE << "AForm sign and execute grade constructor called." << RESET << std::endl;
}
AForm::AForm(std::string name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
	if (executeGrade < 1)
		throw GradeTooHighException();
	else if (executeGrade > 150)
		throw GradeTooLowException();
	std::cout << BLUE << "AForm sign and execute grade constructor called." << RESET << std::endl;
}

// Copy constructor
AForm::AForm(const AForm &toCopy) : _name(toCopy._name), _signed(toCopy._signed), _signGrade(toCopy._signGrade), _executeGrade(toCopy._executeGrade)
{
	std::cout << BLUE << "AForm copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_name = other._name;
		_signed = other._signed;
		// _signGrade = other._signGrade; // unable to copy const grade
		// _executeGrade = other._executeGrade; // unable to copy const grade
	}
	std::cout << BLUE << "AForm copy assignment operator called." << RESET << std::endl;
	return (*this);
}


// Destructor
AForm::~AForm()
{
	std::cout << RED << "AForm destructor called." << RESET << std::endl;
}


// Getters
std::string AForm::getName() const
{
	return (_name);
}
bool AForm::getSigned() const
{
	return (_signed);
}
unsigned int AForm::getSignGrade() const
{
	return (_signGrade);
}
unsigned int AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

// Setters
void AForm::setSignedTrue()
{
	_signed = true;
}

// // Public functions
void AForm::beSigned()
{
	if (_signGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150)
		throw GradeTooLowException();
	_signed = true;
	std::cout << BRIGHT_GREEN << "\""<< _name << "\" has been signed." << RESET << std::endl;
}

// Exception Classes
const char *AForm::GradeTooHighException::what() const throw()
{
	return (BRIGHT_RED "Grade is too high." RESET);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (BRIGHT_RED "Grade is too low." RESET);
}

// Overload << operator
std::ostream& operator<<(std::ostream &o, const AForm &f)
{
	o << BRIGHT_BLUE << "AForm: "<< f.getName() << ", signed: " << (f.getSigned() ? "true" : "false") << ", sign grade: " << f.getSignGrade() << ", execution grade: " << f.getExecuteGrade() << "." << RESET << std::endl;

	return (o);
}