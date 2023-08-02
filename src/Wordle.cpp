/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:03:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 17:18:49 by emajuri          ###   ########.fr       */
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

	std::cout << RED
	<< " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.\n"
	<< "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n"
	<< "| | _____  _____ | || |     ____     | || |  _______     | || |  ________    | || |   _____      | || |  _________   | |\n"
	<< "| ||_   _||_   _|| || |   .'    `.   | || | |_   __ \\    | || | |_   ___ `.  | || |  |_   _|     | || | |_   ___  |  | |\n"
	<< "| |  | | /\\ | |  | || |  /  .--.  \\  | || |   | |__) |   | || |   | |   `. \\ | || |    | |       | || |   | |_  \\_|  | |\n"
	<< "| |  | |/  \\| |  | || |  | |    | |  | || |   |  __ /    | || |   | |    | | | || |    | |   _   | || |   |  _|  _   | |\n"
	<< "| |  |   /\\   |  | || |  \\  `--'  /  | || |  _| |  \\ \\_  | || |  _| |___.' / | || |   _| |__/ |  | || |  _| |___/ |  | |\n"
	<< "| |  |__/  \\__|  | || |   `.____.'   | || | |____| |___| | || | |________.'  | || |  |________|  | || | |_________|  | |\n"
	<< "| |              | || |              | || |              | || |              | || |              | || |              | |\n"
	<< "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n"
	<< " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'\n"
	<< GRN
	<< "   ___         ____          _ __  ____      _____         __       \n"
	<< "  / _ )__ __  / __/__ __ _  (_) / / __/___  / ___/__ _____/ /__  ___\n"
	<< " / _  / // / / _// -_)  ' \\/ / /  > _/_ _/ / /__/ _ `/ __/ / _ \\(_-<\n"
	<< "/____/\\_, / /___/\\__/_/_/_/_/_/  |_____/   \\___/\\_,_/_/ /_/\\___/___/\n"
	<< "     /___/                                                          \n"
	<< WHT;

	database = data;
	correct = database->returnWord();
	for (int i = 0; i < 5; i++) {
		if (getWord(guess) == -1)
			return (-1);
		words[i] = guess;
		display();
		if (guess == correct) {
			std::cout << "Nice work!\n";
			break;
		}
		else if (i == 4)
			std::cout << "The correct word was: " << correct << "\nTry again\n";
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

void	Wordle::printColor(char c, int index, std::string word) {
	if (c == correct[index])
		std::cout << GRN;
	else if (correct.find(c) != std::string::npos) {
		int	count = 0;
		for (int i = 0; i < 5; i++)
			if (correct[i] == c && correct[i] != word[i])
				count++;
		for (int i = 0; i < index; i++)
			if (word[i] == c)
				count--;
		if (count > 0)
			std::cout << YEL;
		else
			std::cout << GRA;
	}
	else
		std::cout << GRA;
	std::cout << c << WHT;
}

void	Wordle::display() {
	for (int i = 0; i < 5; i++) {
		if (words[i].length() == 5) {
			for (int j = 0; j < 5; j++) {
				printColor(words[i][j], j, words[i]);
				if (j < 4)
					std::cout << " ";
			}
		}
		else
			std::cout << "- - - - -";
		std::cout << "\n";
	}
}