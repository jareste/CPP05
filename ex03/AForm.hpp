/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:18:57 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 18:48:43 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# define MIN_GRADE 150
# define MAX_GRADE 1
# define MID_GRADE ((MAX_GRADE - MIN_GRADE) / 2 + MIN_GRADE)
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				formSigned;
		const int			gradeToSign;
		const int			gradeToExe;
		virtual void	exeForm(void) const = 0;
	public:
		AForm();
		AForm( const AForm &form );
		AForm(std::string name, int gradeToSign, int gradeToExe);
		virtual ~AForm();
		AForm		&operator=( const AForm& aForm );
		void		beSigned(const Bureaucrat &bureaucrat);
		void		check_grade_exceptions() const;
		int			getGradeToSign() const;
		int			getGradeToExe() const;
		bool		getAFormSigned() const;
		std::string	getName() const;
		void		execute(Bureaucrat const & bureaucrat) const; 
		virtual std::string				getTarget() const = 0;
		class	GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException(std::string err_msg);
		};
		class	GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException(std::string err_msg);
		};
		class	FormNotSignedException: public std::logic_error
		{
			public:
				FormNotSignedException(std::string err_msg);
		};
};

std::ostream&	operator<<( std::ostream& out, const AForm& aform );

#endif

