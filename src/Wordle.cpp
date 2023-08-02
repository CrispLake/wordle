/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:03:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 16:51:53 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordle.hpp"
#include <iostream>
#include <string>
#include <cctype>

Wordle::Wordle() {
}

void	Wordle::start(Database *data) {
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
		guess = getWord();
		words[i] = guess;
		display();
		if (guess == correct) {
			std::cout << "Nice work!\n";
			break;
		}
		else if (i == 4)
			std::cout << "The correct word was: " << correct << "\nTry again\n";
	}
}

std::string	Wordle::getWord() {
	std::string	word;
	std::getline(std::cin, word);
	if (std::cin.eof())
		; //throw
	else if (word.length() != 5)
		std::cout << "Invalid word\n";
	for (int i = 0; i < 5; i++)
		if (!std::isalpha(word.c_str()[i]))
			; //throw
	return (word);
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
	}
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