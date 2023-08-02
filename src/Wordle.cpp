/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:03:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 13:53:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordle.hpp"
#include <iostream>
#include <string>
#include <cctype>

Wordle::Wordle() {
}

void	Wordle::start() {
	std::string guess;

	for (int i = 0; i < 6; i++) {
		guess = getWord();
		words[i] = guess;
		display();
		if (guess == correct) {
			std::cout << "Nice work!\n";
			break;
		}
		else if (i == 5)
			std::cout << "Try again\n";
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