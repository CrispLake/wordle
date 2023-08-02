/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:31 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/02 16:31:08 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
#define WORDLE_HPP

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
};

#endif