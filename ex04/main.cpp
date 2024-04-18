/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:07:59 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/05 21:58:34 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	replace_and_copy(std::string const &fileName, std::string const &s1, std::string const &s2)
{
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (fileName.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "empty input in args" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	ifs.open(fileName, std::ifstream::in);
	if (!ifs)
	{
		std::cerr << "Failed to open input streams" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	ofs.open(fileName + ".replace", std::ofstream::out);
	if (!ofs)
	{
		std::cerr << "Failed to open output streams" << std::endl;
		std::exit(EXIT_FAILURE);		
	}
	std::string	line;
	while (std::getline(ifs, line))
	{
		std::size_t	i = 0;
		while (true)
		{
			std::size_t	found_pos = line.find(s1, i);
			if (found_pos == std::string::npos)
				break ;
			line.erase(found_pos, s1.size());
			line.insert(found_pos, s2);
			i += s1.size();
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return ;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "invalid number of args" << std::endl;
		return (EXIT_FAILURE);
	}
	replace_and_copy(argv[1], argv[2], argv[3]);
	return (EXIT_SUCCESS);	
}
