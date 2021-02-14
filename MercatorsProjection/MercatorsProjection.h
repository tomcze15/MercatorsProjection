#ifndef MERCATORSPROJECTION_H
#define MERCATORSPROJECTION_H

using namespace std;

constexpr float		RADIUS_OF_EARTH{		637100000.f	}; // Radius of earth.
constexpr int		INTERVAL_MERIDIAN_MAX{	180			}; // ???.
constexpr int		INTERVAL_PARALLEL_MAX{	80			}; // ???.
constexpr int		SUM_MERIDIAN{ INTERVAL_MERIDIAN_MAX + INTERVAL_MERIDIAN_MAX }; // ???.
constexpr int		SUM_PARALLEL{ INTERVAL_PARALLEL_MAX + INTERVAL_PARALLEL_MAX }; // ???.

class MercatorsProjection
{
public:

	/// <summary>
	/// 
	/// </summary>
	/// <param name="rf"></param>
	/// <param name="tiles"></param>
	MercatorsProjection(unsigned rf = 1, unsigned tiles = 4);

	~MercatorsProjection();

	/// <summary>
	/// Sets representative fraction.
	/// </summary>
	/// <param name="rf"> is representative fraction</param>
	void setRF(const unsigned& rf);

	/// <summary>
	/// Gets the current representative fraction.
	/// </summary>
	/// <returns> Representative fraction. </returns>
	unsigned getRF() const;

	float getIntervalMeridian() const;
	float getIntervalParallel() const;

	void setTiles(const int& tiles);

	bool isValid() const;

private:

	/// <summary>
	/// Gets radius of generating globe reduced to given scale.
	/// </summary>
	/// <returns> radius of generating globe reduced to given scale. </returns>
	float getR();

	bool isSquareNumber(const unsigned int& number);

	unsigned int	rf					{}; // Representative fraction
	float			interval_meridian	{}; // ???
	float			interval_parallel	{};	// ???
	unsigned int	tiles				{};	// ???
	float			r					{};	// Radius of generating globe reduced to given scale
	double			ln10				{}; // The result of the natural logarithm
	bool			valid				{};	// ???
	bool			throuhZero			{}; // ???
};

#endif //MERCATORSPROJECTION_H