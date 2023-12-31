/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:49:53 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/31 18:21:50 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTORS */

Fixed::Fixed(void) : rawBits(0) {}

Fixed::Fixed(const Fixed &source) : rawBits(source.rawBits) {}

Fixed::Fixed(const int value)
{
	try
	{
		if (value < -8388608 || value > 8388607)
			throw(1);
		else
			this->rawBits = value << this->fractionalPart;
	}
	catch (int e)
	{
		std::cout << "ERROR: Value " << value << " out of range [-8388608; 8388607]" << std::endl;
	}
}

Fixed::Fixed(const float value)
{
	try
	{
		if (value < -8388608 || value > 8388607)
			throw(1);
		else
			this->rawBits = static_cast<int>(std::roundf(value * (1 << this->fractionalPart)));
	}
	catch (int e)
	{
		std::cout << "ERROR: Value " << value << " out of range [-8388608; 8388607]" << std::endl;
	}
}

/* COMPARISON OPERATORS */

Fixed &Fixed::operator=(const Fixed &source)
{
	this->rawBits = source.rawBits;
	return *this;
}

bool Fixed::operator==(const Fixed &other) const
{
	return other.rawBits == this->rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return other.rawBits != this->rawBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->rawBits > other.rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->rawBits < other.rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->rawBits >= other.rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->rawBits <= other.rawBits);
}

/* ARITHMETIC OPERATORS */

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	res.rawBits = this->rawBits + other.rawBits;
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	res.rawBits = this->rawBits - other.rawBits;
	return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;
	res.rawBits = ((static_cast<int64_t>(this->rawBits) * static_cast<int64_t>(other.rawBits)) >> this->fractionalPart) + (((static_cast<int64_t>(this->rawBits) * static_cast<int64_t>(other.rawBits)) >> (this->fractionalPart - 1)) & 1);
	return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;
	res.rawBits = (static_cast<int64_t>(this->rawBits) << this->fractionalPart) / static_cast<int64_t>(other.rawBits);
	return res;
}

/* INCREMENT/DECREMENT OPERATORS */

Fixed &Fixed::operator++(void)
{
	++(this->rawBits);
	return *this;
}

Fixed &Fixed::operator--(void)
{
	--(this->rawBits);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed original(*this);
	(this->rawBits)++;
	return original;
}

Fixed Fixed::operator--(int)
{
	Fixed original(*this);
	(this->rawBits)--;
	return original;
}

/* OUTPUT OPERATOR */

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	/* UNCOMMENT TO SEE BINARY REPRESENTATION */

	std::bitset<32> a(fixed.getRawBits());
	out << "= [" << a << "]";
	out << " = ";

	out << fixed.toFloat();
	return out;
}

/* DESTRUCTOR */

Fixed::~Fixed(void) {}

/* MEMBER FUNCTIONS */

int Fixed::getRawBits(void) const
{
	return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawBits) / static_cast<float>(1 << this->fractionalPart));
}

int Fixed::toInt(void) const
{
	return this->rawBits >> this->fractionalPart;
}

/* MIN, MAX */

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first > second) ? second : first;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first > second) ? second : first;
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first < second) ? second : first;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first < second) ? second : first;
}