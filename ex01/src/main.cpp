/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/01/09 18:46:00 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

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
	std::cout << BOLD << CYAN << "-------------------------EX01-------------------------"<< RESET << std::endl;
	std::cout << BOLD << CYAN << "------------------------------------------------------"<< RESET << std::endl;
	{
		std::cout << BOLD << CYAN << "\n\tTest 1 (Construction)"<< RESET << std::endl;
		Form defaultForm;
		std::cout << "Announcing: " << defaultForm << RESET;
		Form nameForm("NAME");
		std::cout << "Announcing: " << nameForm << RESET;
		Form signForm(10, 20);
		std::cout << "Announcing: " << signForm << RESET;
		Form nameSignForm("ME", 55, 66);
		std::cout << "Announcing: " << nameSignForm << RESET;
		Form copyForm(signForm);
		std::cout << "Announcing: " << copyForm << RESET;
		Form copyAssignmentForm = nameSignForm;
		std::cout << "Announcing: " << copyAssignmentForm << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 2 (Exception)"<< RESET << std::endl;
		try
		{
			Form gradeTooHighForm("TOO HIGH", 0, 0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Form gradeTooHighForm("TOO HIGH", 0, 55);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Form gradeTooHighForm("TOO HIGH", 55, 0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Form gradeTooLowForm("TOO LOW", 151, 151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Form gradeTooLowForm("TOO LOW", 55, 151);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Form gradeTooLowForm("TOO LOW", 151, 55);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 3 (beSigned)"<< RESET << std::endl;
		Form form("Release form - 1", 50, 50);
		Bureaucrat gradeBureaucrat("SomeGuy", 51);
		std::cout << "Announcing: " << form << RESET;
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << form << RESET;
		gradeBureaucrat.incrementGrade();
		std::cout << "Announcing: " << gradeBureaucrat << RESET;
		try
		{
			gradeBureaucrat.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << form << RESET;
		try
		{
			gradeBureaucrat.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Announcing: " << form << RESET;
	}
	{
		std::cout << BOLD << CYAN << "\n\tTest 4 (getters)"<< RESET << std::endl;
		Form form("Release form - 2", 50, 50);
		std::cout << "Announcing: " << form << RESET;
		std::cout << "Name: " << form.getName() << std::endl;
		std::cout << "Signed: " << form.getSigned() << std::endl;
		std::cout << "SignGrade: " << form.getSignGrade() << std::endl;
		std::cout << "ExecuteGrade: " << form.getExecuteGrade() << std::endl;
	}
}
