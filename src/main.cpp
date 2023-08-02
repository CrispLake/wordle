/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:45:49 by corellan          #+#    #+#             */
/*   Updated: 2023/08/02 14:33:34 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"

int	main()
{
	std::ifstream	file;
	Database		database;

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