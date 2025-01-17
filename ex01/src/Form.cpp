/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/17 17:26:05 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

// Constructor
Form::Form() : _name("default"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << BLUE << "Form default constructor called." << RESET << std::endl;
}
Form::Form(std::string name) : _name(name), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << BLUE << "Form name constructor called." << RESET << std::endl;
}
Form::Form(unsigned int signGrade, unsigned int executeGrade) : _name("default"), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
	if (executeGrade < 1)
		throw GradeTooHighException();
	else if (executeGrade > 150)
		throw GradeTooLowException();
	std::cout << BLUE << "Form sign and execute grade constructor called." << RESET << std::endl;
}
Form::Form(std::string name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
	if (executeGrade < 1)
		throw GradeTooHighException();
	else if (executeGrade > 150)
		throw GradeTooLowException();
	std::cout << BLUE << "Form name, sign and execute grade constructor called." << RESET << std::endl;
}

// Copy constructor
Form::Form(const Form &toCopy) : _name(toCopy._name), _signed(toCopy._signed), _signGrade(toCopy._signGrade), _executeGrade(toCopy._executeGrade)
{
	std::cout << BLUE << "Form copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// _name = other._name; // unable to copy into const
		_signed = other._signed;
		// _signGrade = other._signGrade; // unable to copy const grade
		// _executeGrade = other._executeGrade; // unable to copy const grade
	}
	std::cout << BLUE << "Form copy assignment operator called." << RESET << std::endl;
	return (*this);
}


// Destructor
Form::~Form()
{
	std::cout << RED << "Form destructor called." << RESET << std::endl;
}


// Getters
const std::string Form::getName() const
{
	return (_name);
}
bool Form::getSigned() const
{
	return (_signed);
}
unsigned int Form::getSignGrade() const
{
	return (_signGrade);
}
unsigned int Form::getExecuteGrade() const
{
	return (_executeGrade);
}

// Public functions
void Form::beSigned()
{
	if (_signGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150)
		throw GradeTooLowException();
	_signed = true;
	std::cout << BRIGHT_GREEN << "\""<< _name << "\" has been signed." << RESET << std::endl;
}

// Exception Classes
const char *Form::GradeTooHighException::what() const throw()
{
	return (BRIGHT_RED "Grade is too high." RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (BRIGHT_RED "Grade is too low." RESET);
}

// Overload << operator
std::ostream& operator<<(std::ostream &o, const Form &f)
{
	o << BRIGHT_BLUE << "Form: "<< f.getName() << ", signed: " << (f.getSigned() ? "true" : "false") << ", sign grade: " << f.getSignGrade() << ", execution grade: " << f.getExecuteGrade() << "." << RESET << std::endl;

	return (o);
}