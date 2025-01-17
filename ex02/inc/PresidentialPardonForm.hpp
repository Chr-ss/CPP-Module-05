/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/17 17:12:59 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	std::string			_target;
	// Default constructor moved to private for subject reasons
	PresidentialPardonForm();
public:
	// Constructor
	PresidentialPardonForm(std::string target);
	// PresidentialPardonForm(unsigned int signGrade, unsigned int executeGrade);
	// PresidentialPardonForm(std::string name, unsigned int signGrade, unsigned int executeGrade);

	// Destructor
	~PresidentialPardonForm();

	// Copy Constructor
	PresidentialPardonForm(const PresidentialPardonForm &toCopy);
	// Copy assignment operator
	PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

	// Public functions
	void	beSigned();
	void	execute(Bureaucrat const & executor) const;

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
// std::ostream& operator<<(std::ostream &o, const PresidentialPardonForm &b);

#endif // PresidentialPardonForm_HPP