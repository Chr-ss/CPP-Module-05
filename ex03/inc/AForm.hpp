/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/17 17:12:54 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_executeGrade;
public:
	// Constructor
	AForm();
	AForm(std::string name);
	AForm(unsigned int signGrade, unsigned int executeGrade);
	AForm(std::string name, unsigned int signGrade, unsigned int executeGrade);

	// Destructor
	virtual ~AForm();

	// Copy Constructor
	AForm(const AForm &toCopy);
	// Copy assignment operator
	AForm& operator=(const AForm &other);

	//	Getter
	const std::string	getName() const;
	bool				getSigned() const;
	unsigned int		getSignGrade() const;
	unsigned int		getExecuteGrade() const;

	// Setters
	void				setSignedTrue();

	// Public functions
	virtual void		beSigned() = 0;
	virtual void		execute(Bureaucrat const & executor) const = 0;

	// Exception Classes
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

// ostream Overload
std::ostream& operator<<(std::ostream &o, const AForm &b);

#endif // AForm_HPP