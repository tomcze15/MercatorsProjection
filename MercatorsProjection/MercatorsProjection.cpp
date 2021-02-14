#include "MercatorsProjection.h"
#include <utility>
#include <cmath>

MercatorsProjection::MercatorsProjection(unsigned rf, unsigned tiles)
	:
	rf(					rf						),
	interval_meridian(	INTERVAL_MERIDIAN_MAX	),
	interval_parallel(	INTERVAL_PARALLEL_MAX	),
	r(					RADIUS_OF_EARTH			),
	ln10(				log(10)					),
	tiles(				tiles					),
	valid(				false					),
	throuhZero(			true					)
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

float MercatorsProjection::getIntervalMeridian() const
{
	return this->interval_meridian;
}

float MercatorsProjection::getIntervalParallel() const
{
	return this->interval_parallel;
}

void MercatorsProjection::setTiles(const int& tiles)
{
	if (isSquareNumber(tiles) && 3 < tiles)
	{ 
		valid = false;
		int sqrtOfTiles{ static_cast<int>(sqrt(tiles))};

		this->interval_meridian = SUM_MERIDIAN / static_cast<float>(sqrtOfTiles);
		this->interval_parallel = SUM_PARALLEL / static_cast<float>(sqrtOfTiles);

		if (sqrtOfTiles % 2 == 1)	{ this->throuhZero = false; }
		else						{ this->throuhZero = true;	}
	}
	else { valid = true; }

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
