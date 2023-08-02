/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:28:40 by corellan          #+#    #+#             */
/*   Updated: 2023/08/02 16:47:41 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Database.hpp"

Database::Database()
{
	return ;
}

Database::~Database()
{
	return ;
}

int	Database::storeDatabase(std::ifstream &file)
{
	std::string	temp;

	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: the word.txt file is empty" << std::endl;
		file.close();
		return (-1);
	}
	while (std::getline(file, temp))
	{
		if (_wordValidator(temp) == -1)
		{
			std::cerr << "Error: the word.txt file has invalid entrances" << std::endl;
			file.close();
			return (-1);
		}
		capitalizer(temp);
		_database.push_back(temp);
		file.sync();
	}
	if (file.eof() == true)
	{
		file.close();
		return (0);
	}
	else if (file.fail() == true)
	{
		file.close();
		std::cerr << "Error: Error reading the file" << std:: endl;
		return (-1);
	}
	return (0);
}

int	Database::_wordValidator(std::string const &input)
{
	size_t	i;

	i = 0;
	if (input.size() != 5)
		return (-1);
	while (input[i] && std::isalpha(input[i]))
		i++;
	if (i < input.size())
		return (-1);
	return (0);
}

void	Database::capitalizer(std::string &input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		input[i] = std::toupper(input[i]);
		i++;
	}
	return ;
}

std::string	Database::returnWord()
{
	std::random_device	rd;
	std::uniform_int_distribution<size_t>	dist(0, _database.size());

	return (_database[dist(rd)]);
}

void	Database::printDatabase()
{
	std::vector<std::string>::iterator	it;

	it = _database.begin();
	while (it != _database.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	return ;
}

bool	Database::isInDatabase(std::string const &user)
{
	std::vector<std::string>::iterator	begin;
	std::vector<std::string>::iterator	end;
	std::vector<std::string>::iterator	it;

	begin = _database.begin();
	end = _database.end();
	it = std::find(begin, end, user);
	if (it != end)
		return (true);
	return (false);
}
