/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:18 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/17 17:26:36 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
// #include <random>

// Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << BLUE << "RobotomyRequestForm default constructor called." << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << BLUE << "RobotomyRequestForm target constructor called." << RESET << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy), _target(toCopy._target)
{
	std::cout << BLUE << "RobotomyRequestForm copy constructor called." << RESET << std::endl;
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other._target;
	std::cout << BLUE << "RobotomyRequestForm copy assignment operator called. Unable to assign form values." << RESET << std::endl;
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called." << RESET << std::endl;
}

// Public functions
void	RobotomyRequestForm::beSigned()
{
	AForm::beSigned();
	std::cout << BRIGHT_GREEN << "\""<< AForm::getName() << "\" has been signed." << RESET << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > AForm::getExecuteGrade())
		throw GradeTooLowException();

	std::srand(std::time(0));
	int randomValue = std::rand() % 2;

	// std::random_device rd;  // Seed generator
	// std::mt19937 gen(rd()); // "Mersenne Twister" random number engine
	// std::uniform_int_distribution<int> dist(0, 1); // limit numbers to 0 or 1 with equal probability
	// int randomValue = dist(gen);

	if (randomValue == 0)
		std::cout << BOLD << BRIGHT_GREEN << "Drilling noises... \n" << _target << "..has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << BOLD << BRIGHT_RED << "Drilling noises... \n" << _target << "..the robotomy failed." << RESET << std::endl;
}

AForm*	RobotomyRequestForm::create(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}
