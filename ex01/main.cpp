/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:53:41 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/08 12:26:41 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	freeZombies(Zombie *zombie_head)
{
	delete [] zombie_head;
	zombie_head = NULL;
}

int	main(void)
{
	Zombie	*zombie_head = NULL;
	int		N = 20;

	zombie_head = zombieHorde(N, "Zozotown");
	for (int i = 0; i < N; i++)
	{
		zombie_head[i].announce();
	}
	freeZombies(zombie_head);
	return (EXIT_SUCCESS);
}

#ifdef LEAK_CHECK
#include <libc.h>
__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex01");
}
#endif

//! this leak does not detect - check what is wrong?!