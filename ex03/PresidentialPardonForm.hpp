/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:27:26 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 18:48:37 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
		void	exeForm(void) const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &presidentialPardonForm );
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=( const PresidentialPardonForm& presidentialPardonForm );
		std::string				getTarget() const;
};

#endif
