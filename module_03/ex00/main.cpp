/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:26 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 17:12:23 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ville("Ville");

	/* METHODS */

	ville.attack("Perttu");
	ville.beRepaired(2);
	ville.takeDamage(2);
	ville.beRepaired(2);
	ville.takeDamage(2);
	ville.beRepaired(2);
	ville.takeDamage(2);
	ville.beRepaired(2);
	ville.takeDamage(2);
	ville.beRepaired(2);
	ville.takeDamage(2);
	ville.beRepaired(2);
	ville.takeDamage(2);
	ville.beRepaired(2);
	ville.takeDamage(2);
	ville.beRepaired(2);
	ville.beRepaired(2);
	ville.beRepaired(2);
	ville.attack("Perttu");
	ville.takeDamage(20);
	ville.beRepaired(2);
	ville.attack("Perttu");
	ville.takeDamage(20);

	/* COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR */

	/*
		ClapTrap villeClone(ville);
		villeClone.takeDamage(2);

		ClapTrap perttu("Perttu");
		perttu.takeDamage(2);
		perttu = ville;
		perttu.takeDamage(2);
	 */
	return 0;
}