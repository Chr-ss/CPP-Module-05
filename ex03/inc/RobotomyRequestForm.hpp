/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/17 17:13:09 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
	std::string			_target;
	// Default constructor moved to private for subject reasons
	RobotomyRequestForm();
public:
	// Constructor
	RobotomyRequestForm(std::string target);
	// RobotomyRequestForm(unsigned int signGrade, unsigned int executeGrade);
	// RobotomyRequestForm(std::string name, unsigned int signGrade, unsigned int executeGrade);

	// Destructor
	~RobotomyRequestForm();

	// Copy Constructor
	RobotomyRequestForm(const RobotomyRequestForm &toCopy);
	// Copy assignment operator
	RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

	// Public functions
	void			beSigned();
	void			execute(Bureaucrat const & executor) const;
	static AForm*	create(const std::string &target);

	// // Exception Classes
	// class GradeTooHighException : public std::exception
	// {
	// public:
	// 	const char *what() const throw();
	// };
	// class GradeTooLowException : public std::exception
	// {
	// public:
	// 	const char *what() const throw();
	// };
};

// // ostream Overload
// std::ostream& operator<<(std::ostream &o, const RobotomyRequestForm &b);

#endif // ROBOTOMYREQUESTFORM_HPP