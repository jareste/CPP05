/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:29:47 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/29 21:22:42 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	private:
		AForm	*doPresidentialPardonForm(const std::string target) const;
		AForm	*doRobotomyRequestForm(const std::string target) const;
		AForm	*doShrubberyCreationForm(const std::string target) const;
	public:
		Intern();
		Intern( const Intern &intern );
		~Intern();
		Intern	&operator=( const Intern& intern );
		AForm	*makeForm(std::string formType, std::string formTarget) const;
};

#endif
