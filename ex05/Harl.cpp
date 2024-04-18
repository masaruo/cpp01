/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:33:06 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/05 21:16:36 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << DEBUG_STR << std::endl;
}

void	Harl::info(void)
{
	std::cout << INFO_STR << std::endl;
}

void	Harl::warning(void)
{
	std::cout << WARNING_STR << std::endl;
}

void	Harl::error(void)
{
	std::cout << ERROR_STR << std::endl;
}

void	Harl::complain(std::string level)
{
	// void (Harl::*func[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	void (Harl::*func[MAX_HARL]) (void);
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
	std::string	complain[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < MAX_HARL; i++)
	{
		if (complain[i] == level)
		{
			(this->*func[i])();
			return ;
		}
	}
	std::cout << INVALID_STR << std::endl;
	return ;
}
