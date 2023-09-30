/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:27:31 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 18:18:04 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Undefined")
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &presidentialPardonForm ) : AForm("PresidentialPardonForm", 25, 5), target(presidentialPardonForm.getTarget())
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm& presidentialPardonForm )
{
	this->target = presidentialPardonForm.getTarget();
	AForm::operator=(presidentialPardonForm);
	return (*this);
}

std::string				PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void	PresidentialPardonForm::exeForm(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
