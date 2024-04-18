/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:33:06 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/05 21:42:33 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include "color.hpp"

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
	void (Harl::*func[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	complain[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	for (; i < 4; i++)
	{
		if (complain[i] == level)
		{
			break ;
		}
	}
	switch (i)
	{
		case (DEBUG):
			(this->*func[DEBUG])();
			std::cout << std::endl;
		case (INFO):
			(this->*func[INFO])();
			std::cout << std::endl;
		case (WARNING):
			(this->*func[WARNING])();
			std::cout << std::endl;
		case (ERROR):
			(this->*func[ERROR])();
			std::cout << std::endl;
			break ;
		default:
			std::cout << INVALID_STR << std::endl;
			break ;
	}
	return ;
}
