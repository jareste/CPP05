/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:26:55 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 15:39:00 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Undefined")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &shrubberyCreationForm ) : AForm("ShrubberyCreationForm", 72, 45), target(shrubberyCreationForm.getTarget())
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm& shrubberyCreationForm )
{
	this->formSigned = shrubberyCreationForm.getAFormSigned();
	return (*this);
}

std::string				ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::exeForm(void) const
{
	std::string		file_name;
	file_name = this->getTarget().append("_shrubbery");
	std::ofstream	out_file(file_name);

	if (out_file.fail())
		return (std::cerr << "Error : " << std::strerror(errno) << std::endl, (void) 1);
	out_file << "       ### " << std::endl;
  out_file << "      #o### " << std::endl;
  out_file << "    #####o### " << std::endl;
  out_file << "   #o#\\#|#/### " << std::endl;
  out_file << "    ###\\|/#o# " << std::endl;
  out_file << "     # }|{  # " << std::endl;
  out_file << "       }|{ " << std::endl;
  out_file.close();
}
