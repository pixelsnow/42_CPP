/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:08 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/31 18:21:17 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	/* SUBJECT EXAMPLE */

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	/* MY TESTS */

	Fixed const e(0);
	Fixed const f(0.0f);
	Fixed const g(-100000.005f);
	Fixed const h(100000.005f);
	Fixed const i(-100.005f);
	Fixed const j(100.005f);
	Fixed const k(-8388608);
	Fixed const l(8388607);
	Fixed const m(-8388608.7f);
	Fixed const n(8388607.3f);
	Fixed const o(2147000000);

	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "i is " << i << std::endl;
	std::cout << "j is " << j << std::endl;
	std::cout << "k is " << k << std::endl;
	std::cout << "l is " << l << std::endl;
	std::cout << "m is " << m << std::endl;
	std::cout << "n is " << n << std::endl;

	return 0;
}