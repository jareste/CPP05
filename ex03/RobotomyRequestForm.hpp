/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:27:15 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/29 01:40:34 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	target;
		void	exeForm(void) const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &robotomyRequestForm );
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=( const RobotomyRequestForm& robotomyRequestForm );
		std::string				getTarget() const;
};

#endif