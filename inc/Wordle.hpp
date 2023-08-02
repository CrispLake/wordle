/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:31 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 15:08:30 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
#define WORDLE_HPP

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define WHT "\e[0;37m"

#include <string>

class Wordle {
	public:
		Wordle();

		void	start();

	private:
		std::string	words[6];
		std::string	correct;

		void		display();
		std::string	getWord();
		void		printColor(char c, int index);
};

#endif