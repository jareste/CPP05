/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:18:50 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 18:42:26 by jareste-         ###   ########.fr       */
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
	check_grade_exceptions();
	this->formSigned = form.formSigned;
}

Form::Form(std::string name, int gradeToSign, int gradeToExe) : name(name), gradeToSign(gradeToSign), gradeToExe(gradeToExe)
{
	check_grade_exceptions();
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
	if (bureaucrat.getGrade() <= this->gradeToSign)
		formSigned = true;
	else
		throw Form::GradeTooLowException("grade is too low");
}

void	Form::check_grade_exceptions() const
{
	if (this->gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException("Grade to sign is too high");
	if (this->gradeToSign > 150)
		throw Bureaucrat::GradeTooLowException("Grade to sign is too low");
	if (this->gradeToExe < 1)
		throw Bureaucrat::GradeTooHighException("Grade to exe is too high");
	if (this->gradeToExe > 150)
		throw Bureaucrat::GradeTooLowException("Grade to exe is too low");
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

std::string	Form::getName() const
{
	return (this->name);
}

std::ostream&	operator<<( std::ostream& out, const Form& form )
{
	out << "Form name: " << form.getName() << ", Form sign grade: " \
		<< form.getGradeToSign() << ", Form exec grade: " \
		<< form.getGradeToExe() << ", Form is signed: " \
		<< (form.getFormSigned() ? "true" : "false");
	return ( out );
}
