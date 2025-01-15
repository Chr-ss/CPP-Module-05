/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/01/15 14:37:14 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main(void)
{
	{
		std::cout << BOLD << CYAN << "\n\tTest 1 (Construction)"<< RESET << std::endl;
		Bureaucrat defaultBureaucrat;
		std::cout << "Announcing: " << defaultBureaucrat << RESET;
		Bureaucrat nameBureaucrat("NAME");
		std::cout << "Announcing: " << nameBureaucrat << RESET;
		Bureaucrat gradeBureaucrat(10);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		Bureaucrat nameGradeBureaucrat("ME", 55);
		std::cout << "Announcing: " << nameGradeBureaucrat << RESET;
		Bureaucrat copyBureaucrat(gradeBureaucrat);
		std::cout << "Announcing: " << copyBureaucrat << RESET;
		Bureaucrat copyAssignmentBureaucrat = nameGradeBureaucrat;
		std::cout << "Announcing: " << copyAssignmentBureaucrat << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 2 (Exception)"<< RESET << std::endl;
		try
		{
			Bureaucrat gradeTooHighBureaucrat("TOO HIGH", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat gradeTooLowBureaucrat("TOO LOW", 151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 3 (increment/decrement)"<< RESET << std::endl;
		Bureaucrat gradeBureaucrat("SomeGuy", 88);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.incrementGrade();
			std::cout << "Announcing: " << gradeBureaucrat << RESET;
			gradeBureaucrat.decrementGrade();
			std::cout << "Announcing: " << gradeBureaucrat << RESET;
			gradeBureaucrat.decrementGrade();
			std::cout << "Announcing: " << gradeBureaucrat << RESET;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 4 (setGrade)"<< RESET << std::endl;
		Bureaucrat gradeBureaucrat("LameGuy", 66);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.setGrade(0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.setGrade(151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.setGrade(1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 5 (getters)"<< RESET << std::endl;
		Bureaucrat gradeBureaucrat("CoolGuy", 1);
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		std::cout << "Name: " << gradeBureaucrat.getName() << std::endl;
		std::cout << "Grade: " << gradeBureaucrat.getGrade() << std::endl;
	}
	std::cout << BOLD << CYAN << "\n\n------------------------------------------------------"<< RESET << std::endl;
	std::cout << BOLD << CYAN << "-------------------------EX02-------------------------"<< RESET << std::endl;
	std::cout << BOLD << CYAN << "------------------------------------------------------"<< RESET << std::endl;
	{
		std::cout << BOLD << CYAN << "\n\tTest 6 (Form construction)"<< RESET << std::endl;
		ShrubberyCreationForm ShrubberyCreationForm1("Release ShrubberyCreationForm - 1");
		std::cout << "Announcing: " << ShrubberyCreationForm1 << RESET;
		RobotomyRequestForm RobotomyRequestForm1("Release RobotomyRequestForm - 1");
		std::cout << "Announcing: " << RobotomyRequestForm1 << RESET;
		PresidentialPardonForm PresidentialPardonForm1("Release PresidentialPardonForm - 1");
		std::cout << "Announcing: " << PresidentialPardonForm1 << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 7 (sign and execute ShrubberyCreationForm)"<< RESET << std::endl;
		ShrubberyCreationForm ShrubberyCreationForm1("Release ShrubberyCreationForm - 4");
		Bureaucrat gradeBureaucrat("SomeGuy", 146);
		std::cout << "Announcing: " << ShrubberyCreationForm1 << RESET;
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.signForm(ShrubberyCreationForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << ShrubberyCreationForm1 << RESET;
		gradeBureaucrat.incrementGrade();
		try
		{
			gradeBureaucrat.signForm(ShrubberyCreationForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << ShrubberyCreationForm1 << RESET;
		for (int i = 0; i < 7; i++)
			gradeBureaucrat.incrementGrade();
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.executeForm(ShrubberyCreationForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		gradeBureaucrat.incrementGrade();
		std::cout << "\nAnnouncing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.executeForm(ShrubberyCreationForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << ShrubberyCreationForm1 << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 8 (sign and execute RobotomyRequestForm)"<< RESET << std::endl;
		RobotomyRequestForm RobotomyRequestForm1("Release RobotomyRequestForm - 4");
		Bureaucrat gradeBureaucrat("SomeGuy", 73);
		std::cout << "Announcing: " << RobotomyRequestForm1 << RESET;
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.signForm(RobotomyRequestForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << RobotomyRequestForm1 << RESET;
		gradeBureaucrat.incrementGrade();
		try
		{
			gradeBureaucrat.signForm(RobotomyRequestForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << RobotomyRequestForm1 << RESET;
		for (int i = 0; i < 26; i++)
			gradeBureaucrat.incrementGrade();
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.executeForm(RobotomyRequestForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		gradeBureaucrat.incrementGrade();
		std::cout << "\nAnnouncing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.executeForm(RobotomyRequestForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << RobotomyRequestForm1 << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 9 (sign and execute PresidentialPardonForm)"<< RESET << std::endl;
		PresidentialPardonForm PresidentialPardonForm1("Release PresidentialPardonForm - 4");
		Bureaucrat gradeBureaucrat("SomeGuy", 26);
		std::cout << "Announcing: " << PresidentialPardonForm1 << RESET;
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.signForm(PresidentialPardonForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << PresidentialPardonForm1 << RESET;
		gradeBureaucrat.incrementGrade();
		try
		{
			gradeBureaucrat.signForm(PresidentialPardonForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << PresidentialPardonForm1 << RESET;
		for (int i = 0; i < 19; i++)
			gradeBureaucrat.incrementGrade();
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.executeForm(PresidentialPardonForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		gradeBureaucrat.incrementGrade();
		std::cout << "\nAnnouncing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.executeForm(PresidentialPardonForm1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nAnnouncing: " << PresidentialPardonForm1 << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 10 (50% test RobotomyRequestForm)"<< RESET << std::endl;
		RobotomyRequestForm RobotomyRequestForm1("Release RobotomyRequestForm - 4");
		Bureaucrat gradeBureaucrat("SomeGuy", 10);
		gradeBureaucrat.signForm(RobotomyRequestForm1);
		std::cout << "\n" << RESET << std::endl;
		for (int i = 0; i < 10; i++)
		{
			gradeBureaucrat.executeForm(RobotomyRequestForm1);
		}
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 11 (Intern creation)"<< RESET << std::endl;
		Intern someIntern;
		AForm *ShrubberyCreationForm1 = someIntern.makeForm("shrubbery creation", "Release ShrubberyCreationForm - 1");
		AForm *RobotomyRequestForm1 = someIntern.makeForm("robotomy request", "Release RobotomyRequestForm - 1");
		AForm *PresidentialPardonForm1 = someIntern.makeForm("presidential pardon", "Release PresidentialPardonForm - 1");


		std::cout << "Announcing: " << *ShrubberyCreationForm1 << RESET;
		std::cout << "Announcing: " << *RobotomyRequestForm1 << RESET;
		std::cout << "Announcing: " << *PresidentialPardonForm1 << RESET;
		delete ShrubberyCreationForm1;
		delete RobotomyRequestForm1;
		delete PresidentialPardonForm1;
	}
}
