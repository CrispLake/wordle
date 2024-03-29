/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:31 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 17:17:51 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
#define WORDLE_HPP

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define WHT "\e[0;37m"
#define GRA "\e[38;5;243m"

#include <string>
#include "Database.hpp"

class Wordle {
	public:
		Wordle();

		int	start(Database *data);

	private:
		std::string	words[6];
		std::string	correct;
		Database	*database;


		void	display();
		int		getWord(std::string &word);
		void		printColor(char c, int index, std::string word);
};

#endif