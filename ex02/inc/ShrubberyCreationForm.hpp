/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/15 13:39:07 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
private:
	std::string			_target;
	// Default constructor moved to private for subject reasons
	ShrubberyCreationForm();
public:
	// Constructor
	ShrubberyCreationForm(std::string target);
	// ShrubberyCreationForm(unsigned int signGrade, unsigned int executeGrade);
	// ShrubberyCreationForm(std::string name, unsigned int signGrade, unsigned int executeGrade);

	// Destructor
	~ShrubberyCreationForm();

	// Copy Constructor
	ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
	// Copy assignment operator
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

	// Public functions
	void	beSigned();
	void	executeForm(Bureaucrat const & executor) const;

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
// std::ostream& operator<<(std::ostream &o, const ShrubberyCreationForm &b);

#endif // ShrubberyCreationForm_HPP