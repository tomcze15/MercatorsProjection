#include "MercatorsProjection.h"
#define _USE_MATH_DEFINES
#include <utility>
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

float MercatorsProjection::getParallelHeightInCms(const float& parralel_pos)
{
	return this->ln10 * this->r * log10( tan(degreesToRadian( (90 + parralel_pos) * 0.5f )) );
}

vector<vector<Point>> MercatorsProjection::createMap()
{
	if (valid == false)
	{
		vector<vector<Point>> points;

		int count{	0 },
			size{	static_cast<int>( this->sqrtTiles * 0.5f ) + 1	},
			actuallyMeridianPos{ INTERVAL_MERIDIAN_MAX	* (-1)		},
			actuallyParallelPos{ INTERVAL_PARALLEL_MAX				};

		float xPos{0.f};
		float yPos{ getParallelHeightInCms(actuallyParallelPos) };

		for (unsigned i{}; i < size; i++)
		{
			vector<Point> parallels;
			yPos = getParallelHeightInCms(actuallyParallelPos);

			for (unsigned j{}; j < (this->sqrtTiles + 1); j++)
			{
				Point point;
				point.meridian_pos = actuallyMeridianPos;
				point.parallel_pos = actuallyParallelPos;
				point.x = xPos;
				point.y = yPos;
				parallels.push_back(point);
				actuallyMeridianPos += this->interval_meridian;
				xPos += this->r;
			}
			points.push_back(parallels);
			xPos = 0.f;
			actuallyMeridianPos = INTERVAL_MERIDIAN_MAX * (-1);
			actuallyParallelPos -= this->interval_parallel;
		}

		auto copy_points{ points };

		if (this->throuhZero)
			copy_points.pop_back();

		std::reverse(copy_points.begin(), copy_points.end());

		for (auto& points : copy_points)
		{
			for (auto& point : points)
			{
				point.meridian_pos *= -1;
				point.parallel_pos *= -1;
			}
		}

		points.insert(points.end(), copy_points.begin(), copy_points.end());
		return points;
	}
	return vector<vector<Point>>();
}