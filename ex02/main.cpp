/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:58:06 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/03 14:20:48 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout 
	<< "memory address of *HI THIS IS Brain* [" << &str << "]"
	<< " | *held by pointer* [" << stringPTR << "]" 
	<< " | *held by reference* [" << &stringREF << "]" << std::endl;
	std::cout
	<< "value of string* [" << str << "]"
	<< " | *value pointed by stringPTR* [" << *stringPTR << "]"
	<< " | *value pointed by stringREF* [" << stringREF << "]" << std::endl;
	return (EXIT_SUCCESS);
}
