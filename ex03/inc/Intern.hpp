/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/01/15 14:16:26 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
class AFrom;

class Intern{
public:
	// Constructor
	Intern();

	// Destructor
	~Intern();

	// Copy Constructor
	Intern(const Intern &toCopy);
	// Copy assignment operator
	Intern& operator=(const Intern &other);

	// Public functions
	AForm*	makeForm(std::string formName, std::string target);
};

#endif // INTERN_HPP