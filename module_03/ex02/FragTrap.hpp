/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:45:09 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 16:25:49 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"
#include "colours.hpp"
#include <iostream>

class FragTrap : public ScavTrap
{
private:
public:
	FragTrap(std::string newName);
	~FragTrap(void);

	void highFivesGuys(void);
};

#endif