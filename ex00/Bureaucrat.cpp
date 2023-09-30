/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:20:44 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 17:52:09 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string err_msg) : std::out_of_range(err_msg)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string err_msg) : std::out_of_range(err_msg)
{
}

Bureaucrat::Bureaucrat() : name("Noname")
{
	this->grade = 75;
}

Bureaucrat::Bureaucrat( const Bureaucrat &bureaucrat ) : name(bureaucrat.getName())
{
	this->grade = bureaucrat.getGrade();
}

Bureaucrat::Bureaucrat(const std::string Name, int grade) : name(Name)
{
	this->grade = grade;
	check_grade_exceptions();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat& bureaucrat )
{
	this->grade = bureaucrat.getGrade();
	return (*this);
}

void		Bureaucrat::incrementGrade()
{
	this->grade--;
	check_grade_exceptions();
}

void		Bureaucrat::incrementGrade(int grade)
{
	this->grade -= grade;
	check_grade_exceptions();
}

void		Bureaucrat::decrementGrade()
{
	this->grade++;
	check_grade_exceptions();
}

void		Bureaucrat::decrementGrade(int grade)
{
	this->grade += grade;
	check_grade_exceptions();
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::check_grade_exceptions()
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade was too high.");
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade was too low.");
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ( out );
}
