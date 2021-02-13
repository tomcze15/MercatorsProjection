#include "MercatorsProjection.h"
#include <utility>
#include <cmath>

MercatorsProjection::MercatorsProjection()
	:
	rf(1),
	r(RADIUS_OF_EARTH),
	ln10(log(10)),
	tiles(4),
	valid(false)
{
}

MercatorsProjection::~MercatorsProjection()
{
}

void MercatorsProjection::setRF(const unsigned& rf)
{
	this->rf = rf;
	this->r = RADIUS_OF_EARTH / static_cast<float>(this->rf);
}

unsigned MercatorsProjection::getRF() const
{
	return this->rf;
}

unsigned char MercatorsProjection::getInterval() const
{
	return this->interval;
}

void MercatorsProjection::setTiles(const int& tiles)
{
	if (isSquareNumber(tiles) && 3 < tiles)
	{ 
		valid = false; 
		//this->interval;
	}
	else									 
	{ 
		valid = true; 
	}

	this->tiles = tiles;
}

bool MercatorsProjection::isValid() const
{
	return this->valid;
}

float MercatorsProjection::getR()
{
	return this->r;
}

bool MercatorsProjection::isSquareNumber(const unsigned int& number)
{
	auto sqrtOfNumber{ sqrt(number) };
	return (sqrtOfNumber - static_cast<int>(sqrtOfNumber) == .0) ? true : false;
}
