#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat	bureaucrat137("Bureaucrat137", 137);
		std::cout << bureaucrat137 << std::endl;
		Bureaucrat	internBureaucrat("InternBureaucrat", 150);
		std::cout << internBureaucrat << std::endl;
		Bureaucrat	CEOBureaucrat("CEOBureaucrat", 1);
		std::cout << CEOBureaucrat << std::endl;

		ShrubberyCreationForm form("ShrubberyTarget");
		std::cout << form << std::endl;
		bureaucrat137.signForm(form);
		std::cout << form << std::endl;
		bureaucrat137.executeForm(form);

		RobotomyRequestForm robotomyFrom("RobotomyTarget");
		CEOBureaucrat.signForm(robotomyFrom);
		std::cout << robotomyFrom << std::endl;
		CEOBureaucrat.executeForm(robotomyFrom);

		PresidentialPardonForm presidentialForm("PresidentialTarget");
		CEOBureaucrat.signForm(presidentialForm);
		std::cout << presidentialForm << std::endl;
		CEOBureaucrat.executeForm(presidentialForm);
		bureaucrat137.executeForm(presidentialForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
