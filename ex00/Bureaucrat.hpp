/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:20:48 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/28 11:31:51 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# define MIN_GRADE 150
# define MAX_GRADE 1
# define MID_GRADE ((MAX_GRADE - MIN_GRADE) / 2 + MIN_GRADE)

class Bureaucrat
{
	private:
		const std::string	name;
		int			grade;
		void		check_grade_exceptions();
	
	public:
		Bureaucrat();
		Bureaucrat( const Bureaucrat &bureaucrat );
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat	&operator=( const Bureaucrat& bureaucrat );
		void		incrementGrade();
		void		incrementGrade(int grade);
		void		decrementGrade();
		void		decrementGrade(int grade);
		const std::string	getName() const;
		int			getGrade() const;
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

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif
