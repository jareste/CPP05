/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:29:42 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/29 21:33:16 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern &intern )
{
	(void) intern;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=( const Intern& intern )
{
	(void) intern;
	return (*this);
}

AForm	*Intern::doPresidentialPardonForm(const std::string target) const
{
	std::cout << "Intern creates Presidential Pardon." << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::doRobotomyRequestForm(const std::string target) const
{
	std::cout << "Intern creates Robotomy Request." << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::doShrubberyCreationForm(const std::string target) const
{
	std::cout << "Intern creates ShrubberyCreation." << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string formType, std::string formTarget) const
{
	std::string forms[3]= \
	{"presidential pardon", \
	 "robotomy request", \
	 "shrubbery creation"};

	AForm	*(Intern::*createForm[3])(const std::string) const = \
	{&Intern::doPresidentialPardonForm, \
	 &Intern::doRobotomyRequestForm, \
	 &Intern::doShrubberyCreationForm};

	 for (int i = 0; i < 3 ; i++)
	 	if (forms[i] == formType)
	 		return ((this->*createForm[i])(formTarget));

 	std::cout << formType << " is an invalid form type." << std::endl;
 	return NULL;
}
