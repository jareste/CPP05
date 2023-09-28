/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:18:57 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/28 16:20:12 by jareste-         ###   ########.fr       */
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

class Form
{
	private:
		const std::string	name;
		bool				formSigned;
		const int			gradeToSign;
		const int			gradeToExe;
	public:
		Form();
		Form( const Form &form );
		Form(std::string name, int gradeToSign, int gradeToExe);
		~Form();
		Form		&operator=( const Form& form );
		void		beSigned(const Bureaucrat &bureaucrat);
		int			getGradeToSign() const;
		int			getGradeToExe() const;
		bool		getFormSigned() const;
		std::string	getName() const;
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

};

std::ostream&	operator<<( std::ostream& out, const Form& form );

#endif

