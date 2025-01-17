/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/17 17:22:49 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << BLUE << "Bureaucrat default constructor called." << RESET << std::endl;
}
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
	std::cout << BLUE << "Bureaucrat name constructor called." << RESET << std::endl;
}
Bureaucrat::Bureaucrat(unsigned int grade) : _name("default")
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << BLUE << "Bureaucrat grade constructor called." << RESET << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << BLUE << "Bureaucrat constructor called." << RESET << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &toCopy) : _name(toCopy._name), _grade(toCopy._grade)
{
	std::cout << BLUE << "Bureaucrat copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// _name = other._name; // unable to copy into const
		_grade = other._grade;
	}
	std::cout << BLUE << "Bureaucrat copy assignment operator called." << RESET << std::endl;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called." << RESET << std::endl;
}


// Getters
const std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

// Setters
void Bureaucrat::setGrade(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

// Public functions
void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	if (f.getSigned())
	{
		std::cout << BRIGHT_GREEN << "\"" << f.getName() << "\" already signed." << RESET << std::endl;
	}
	else if (f.getSignGrade() >= _grade)
	{
		std::cout << BRIGHT_GREEN << _name << " signs AForm \"" << f.getName() << "\". " << RESET;
		f.beSigned();
	}
	else
	{
		std::cout << BRIGHT_RED << _name << " cannot sign " << f.getName() << " because grade is too low." << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &f) const
{
	if (!f.getSigned())
	{
		std::cout << BRIGHT_RED << _name << " cannot execute " << f.getName() << " because form is not signed." << RESET << std::endl;
		return ;
	}
	if (_grade <= f.getExecuteGrade())
	{
		std::cout << BRIGHT_GREEN << _name << " executes AForm \"" << f.getName() << "\"." << RESET << std::endl;
		f.execute(*this);
	}
	else
	{
		std::cout << BRIGHT_RED << _name << " cannot execute " << f.getName() << " because grade is too low." << RESET << std::endl;
	}
}

// Exception Classes
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BRIGHT_RED "Grade is too high." RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BRIGHT_RED "Grade is too low." RESET);
}

// Overload << operator
std::ostream& operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << BRIGHT_BLUE << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET << std::endl;

	return (o);
}