/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:45:49 by corellan          #+#    #+#             */
/*   Updated: 2023/08/02 14:54:52 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordle.hpp"

int	main()
{
	std::ifstream	file;
	Wordle			wordle;
	Database		database;

	file.open("words.txt");
	if (file.fail() == true)
	{
		std::cerr << "Error: Error reading words.txt file" << std::endl;
		return (1);
	}
	if (database.storeDatabase(file) == -1)
		return (1);
	wordle.start(&database);
	return (0);
}