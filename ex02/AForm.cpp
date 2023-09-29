/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:18:50 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/29 03:31:16 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(std::string err_msg) : std::out_of_range(err_msg)
{
}

AForm::GradeTooLowException::GradeTooLowException(std::string err_msg) : std::out_of_range(err_msg)
{
}

AForm::FormNotSignedException::FormNotSignedException(std::string err_msg) : std::logic_error(err_msg)
{
}

AForm::AForm() : name("Undefined"), gradeToSign(75), gradeToExe(75)
{
	formSigned = false;
}

AForm::AForm( const AForm &aform ) : name(aform.name), gradeToSign(aform.gradeToSign), gradeToExe(aform.gradeToExe)
{
	this->formSigned = aform.formSigned;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExe) : name(name), gradeToSign(gradeToSign), gradeToExe(gradeToExe)
{
	formSigned = false;
}

AForm::~AForm()
{
}

AForm	&AForm::operator=( const AForm& aform )
{
	this->formSigned = aform.getAFormSigned();
	return (*this);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < this->gradeToSign)
		formSigned = true;
	else
		throw AForm::GradeTooLowException("grade is too low");
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExe() const
{
	return (this->gradeToExe);
}

bool		AForm::getAFormSigned() const
{
	return (this->formSigned);
}

std::string	AForm::getName() const
{
	return (this->name);
}

void		AForm::execute(Bureaucrat const & bureaucrat) const 
{
	if (formSigned == false)
		throw AForm::FormNotSignedException("form is not signed");
	if (bureaucrat.getGrade() > this->gradeToExe)
		throw AForm::GradeTooLowException("grade is too low");
	exeForm();
}

std::ostream&	operator<<( std::ostream& out, const AForm& aform )
{
	out << "AForm name: " << aform.getName() << ", AForm sign grade: " \
		<< aform.getGradeToSign() << ", AForm exec grade: " \
		<< aform.getGradeToExe() << ", AForm is signed: " \
		<< (aform.getAFormSigned() ? "true" : "false");
	return ( out );
}
