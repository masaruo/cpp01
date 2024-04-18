/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:15:28 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/04 16:39:22 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	input;

	if (argc == 2)
	{
		harl.complain(argv[1]);
	}
	else
	{
		std::cerr << "invalid number of args" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
