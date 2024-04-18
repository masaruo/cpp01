/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:53:41 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/02 22:07:44 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack_z = Zombie("stack_zombie");
	Zombie	*heap_z = newZombie("heap_zombie");

	stack_z.announce();
	heap_z->announce();
	randomChump("randomChump_zombie");
	delete heap_z;
	return (EXIT_SUCCESS);
}