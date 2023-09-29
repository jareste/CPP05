/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:26:50 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/29 03:36:21 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	target;
		void	exeForm(void) const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm &shrubberyCreationForm );
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm& shrubberyCreationForm );
		std::string				getTarget() const;
};

#endif