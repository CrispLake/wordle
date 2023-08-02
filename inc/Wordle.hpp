/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:31 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 13:47:01 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
#define WORDLE_HPP

#include <string>

class Wordle {
	public:
		Wordle();

		void	start();

	private:
		std::string	words[6];
		std::string	correct;

		void	display();
		std::string	getWord();
};

#endif