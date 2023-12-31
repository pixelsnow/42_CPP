/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:57 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 17:27:51 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "colours.hpp"

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal &source);
	virtual ~Animal(void);

	Animal &operator=(const Animal &source);

	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif