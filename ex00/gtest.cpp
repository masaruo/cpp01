/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtest.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/02 21:53:25 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"

TEST(Zombie, checkAnnounceWithoutProvidingName)
{
	std::streambuf 		*coutBuf = std::cout.rdbuf();
	std::ostringstream	oss;
	Zombie	z;

	std::cout.rdbuf(oss.rdbuf());
	z.announce();
	EXPECT_EQ(oss.str(), "undefined: BraiiiiiiinnnzzzZ...\n");
	std::cout.rdbuf(coutBuf);
}

TEST(Zombie, checkAnnounceWithNameProvided)
{
	std::streambuf 		*coutBuf = std::cout.rdbuf();
	std::ostringstream	oss;
	Zombie	z("42 tokyo");

	std::cout.rdbuf(oss.rdbuf());
	z.announce();
	EXPECT_EQ(oss.str(), "42 tokyo: BraiiiiiiinnnzzzZ...\n");
	std::cout.rdbuf(coutBuf);
}

TEST(Zombie, createZombieInHeap)
{
	std::streambuf 		*coutBuf = std::cout.rdbuf();
	std::ostringstream	oss;
	Zombie	*z = newZombie("z In Heap");

	std::cout.rdbuf(oss.rdbuf());
	z->announce();
	EXPECT_EQ(oss.str(), "z In Heap: BraiiiiiiinnnzzzZ...\n");
	std::cout.rdbuf(coutBuf);
	delete z;
}

TEST(Zombie, randomChumpCheck)
{
	std::streambuf 		*coutBuf = std::cout.rdbuf();
	std::ostringstream	oss;
	
	std::cout.rdbuf(oss.rdbuf());
	randomChump("random Chump Zombie");
	EXPECT_EQ(oss.str(), "random Chump Zombie: BraiiiiiiinnnzzzZ...\n");
	std::cout.rdbuf(coutBuf);
}