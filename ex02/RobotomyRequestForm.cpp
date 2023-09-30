/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:27:11 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 18:18:46 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &robotomyRequestForm ) : AForm("RobotomyRequestForm", 72, 45), target(robotomyRequestForm.getTarget())
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm& robotomyRequestForm )
{
	this->target = robotomyRequestForm.getTarget();
	AForm::operator=(robotomyRequestForm);
	return (*this);
}

std::string				RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::exeForm(void) const
{
	std::srand(std::time(0));

	if (rand() % 2)
		std::cout << target << " has been Robotomized." << std::endl;
	else
		std::cout << target << " robotomy failed..." << std::endl;
}

