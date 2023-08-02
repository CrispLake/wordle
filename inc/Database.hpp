/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:28:43 by corellan          #+#    #+#             */
/*   Updated: 2023/08/02 14:34:01 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
# define DATABASE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <vector>
# include <random>
# include <algorithm>

class Database
{
private:

	std::vector<std::string>	_database;

	Database(Database const &rhs);

	Database	&operator=(Database const &rhs);

	int		_wordValidator(std::string const &input);
	void	_capitalizer(std::string &input);

public:

	Database();
	~Database();

	int			storeDatabase(std::ifstream &file);
	void		printDatabase(); //FOR DEBUGGING
	bool		isInDatabase(std::string const &user);
	std::string	returnWord();

};

#endif
