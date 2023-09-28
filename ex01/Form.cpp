/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:18:50 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/28 12:32:19 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(std::string err_msg) : std::out_of_range(err_msg)
{
}

Form::GradeTooLowException::GradeTooLowException(std::string err_msg) : std::out_of_range(err_msg)
{
}


Form::Form() : name("Undefined"), gradeToSign(75), gradeToExe(75)
{
	formSigned = false;
}

Form::Form( const Form &form ) : name(form.name), gradeToSign(form.gradeToSign), gradeToExe(form.gradeToExe)
{
	this->formSigned = form.formSigned;
}

Form::Form(std::string name, int gradeToSign, int gradeToExe) : name(name), gradeToSign(gradeToSign), gradeToExe(gradeToExe)
{
	formSigned = false;
}

Form::~Form()
{
}

Form	&Form::operator=( const Form& form )
{
	this->formSigned = form.getFormSigned();
	return (*this);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < this->gradeToSign)
		formSigned = true;
	else
		throw Form::GradeTooLowException("");
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExe() const
{
	return (this->gradeToExe);
}

bool		Form::getFormSigned() const
{
	return (this->formSigned);
}

