/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:46:03 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/05 11:00:46 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie				*zombies;
	std::stringstream	out;

	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		out.str("");
		out.clear();
		out << i;
		zombies[i].setName(name + "[" + out.str() + "]");
		// zombies[i].setName(name + std::to_string(i));
	}
	return (zombies);
}

// std::to_string = cpp11?
// but can compile with -std=c++98
// https://cpprefjp.github.io/reference/string/to_string.html