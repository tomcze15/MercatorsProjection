#include "MercatorsProjection.h"
#define _USE_MATH_DEFINES
#include <utility>
//#include <cmath>
#include <math.h>

MercatorsProjection::MercatorsProjection(unsigned rf, unsigned tiles)
	:
	rf(					rf						),
	interval_meridian(	INTERVAL_MERIDIAN_MAX	),
	interval_parallel(	INTERVAL_PARALLEL_MAX	),
	r(					RADIUS_OF_EARTH			),
	ln10(				log(10)					),
	tiles(				tiles					),
	sqrtTiles(			sqrt(tiles)				),
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
		int sqrtOfTiles{ static_cast<int>(this->sqrtTiles)};

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
	this->sqrtTiles = sqrt(number);
	return (this->sqrtTiles - static_cast<int>(this->sqrtTiles) == .0) ? true : false;
}

double MercatorsProjection::degreesToRadian(const float& degrees)
{
	return (degrees * M_PI) / 180.0f;
}

float MercatorsProjection::getParallelHeightInCMS(const float& parralel_pos)
{
	return this->ln10 * this->r * log10(tan((degreesToRadian(90) + degreesToRadian(20)) / 2));
}

vector<vector<Point>> MercatorsProjection::createMap()
{
	if (valid == false)
	{
		int count{	0 },
			size{	static_cast<int>( this->sqrtTiles * 0.5f ) 	},
			actuallyMeridianPos{ INTERVAL_MERIDIAN_MAX	* (-1)	},
			actuallyParallelPos{ INTERVAL_PARALLEL_MAX	* (-1)	};

		if (!this->throuhZero) { size += 1; }

		float* parallelsHeightsInCMS{ new float[size] };

		Point p;
		p.meridian_pos = actuallyMeridianPos;
		p.parallel_pos = actuallyParallelPos;
		p.x = 0;
		p.y = 0;



		for (unsigned i{}; i < size; i++)
		{

		}
	}
	return vector<vector<Point>>();
}