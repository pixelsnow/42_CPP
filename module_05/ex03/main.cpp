#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;
		AForm* shrubbery;
		AForm* robotomy;
		AForm* presidential;

		shrubbery = someRandomIntern.makeForm("shrubbery", "ShrubberyTarget");
		std::cout << *shrubbery << std::endl;
		robotomy = someRandomIntern.makeForm("robotomy", "RobotomyTarget");
		std::cout << *robotomy << std::endl;
		presidential = someRandomIntern.makeForm("presidential", "PresidentialTarget");
		std::cout << *presidential << std::endl;

		// FORM EXECUTION TEST

		Bureaucrat	CEOBureaucrat("CEOBureaucrat", 1);
		CEOBureaucrat.executeForm(*shrubbery);
		CEOBureaucrat.executeForm(*robotomy);
		CEOBureaucrat.executeForm(*presidential);

		AForm* wrong;
		wrong = someRandomIntern.makeForm("wrong", "WrongTarget");
		std::cout << *wrong << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
