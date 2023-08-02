/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:03:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 16:53:16 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordle.hpp"
#include <iostream>
#include <string>
#include <cctype>

Wordle::Wordle() {
}

int	Wordle::start(Database *data) {
	std::string guess;

	database = data;
	correct = database->returnWord();
	for (int i = 0; i < 6; i++) {
		if (getWord(guess) == -1)
			return (-1);
		words[i] = guess;
		display();
		if (guess == correct) {
			std::cout << "Nice work!\n";
			break;
		}
		else if (i == 4)
			std::cout << "Try again\n";
	}
	return (0);
}

int	Wordle::getWord(std::string &word) {
	int	flag;

	while (1)
	{
		flag = 0;
		std::getline(std::cin, word);
		if (std::cin.eof())
		{
			std::cerr << "You chose to close the program. Good luck next time" << std::endl;
			return (-1);
		}
		else if (word.length() != 5)
		{
			std::cerr << "Invalid word" << std::endl;
			std::cin.sync();
			continue ;
		}
		for (int i = 0; ((i < 5) && (flag == 0)); i++)
		{
			if (!std::isalpha(word[i]))
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 1)
		{
			std::cerr << "Invalid word" << std::endl;
			std::cin.sync();
			continue ;
		}
		std::cin.sync();
		break ;
	}
	database->capitalizer(word);
	return (0);
}

void	Wordle::display() {
	for (int i = 0; i < 5; i++) {
		if (words[i].length() == 5) {
			for (int j = 0; j < 5; j++) {
				std::cout << words[i][j];
				if (j < 4)
					std::cout << " ";
			}
		}
		else
			std::cout << "- - - - -";
		std::cout << "\n";
	}
}