/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:45:49 by corellan          #+#    #+#             */
/*   Updated: 2023/08/02 14:17:06 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"

int	main(int ac, char **av)
{
	std::ifstream	file;
	Database		database;

	if (!av[0])
		return (1);
	if (ac != 1)
	{
		std::cerr << "Error: No parameters allowed." << std::endl;
		return (1);
	}
	file.open("words.txt");
	if (file.fail() == true)
	{
		std::cerr << "Error: Error reading words.txt file" << std::endl;
		return (1);
	}
	if (database.storeDatabase(file) == -1)
		return (1);
	std::cout << database.returnWord() << std::endl;
	if (database.isInDatabase("ABBA") == true)
		std::cout << "ZORRO" << std::endl;
	else
		std::cout << "VOI VITTU!!" << std::endl;
	return (0);
}