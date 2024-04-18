/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:47:12 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/02 22:02:47 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string name = "undefined");
		~Zombie(void);
		void	announce(void);
};

Zombie	*newZombie(std::string	name);
void	randomChump(std::string	name);

#endif