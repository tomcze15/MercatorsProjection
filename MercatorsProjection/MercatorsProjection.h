#ifndef MERCATORSPROJECTION_H
#define MERCATORSPROJECTION_H
#include <vector>

using namespace std;

constexpr float		RADIUS_OF_EARTH{		637100000.f	}; // Radius of earth.
constexpr int		INTERVAL_MERIDIAN_MAX{	180			}; // ???.
constexpr int		INTERVAL_PARALLEL_MAX{	90			}; // ???.
constexpr int		SUM_MERIDIAN{ INTERVAL_MERIDIAN_MAX + INTERVAL_MERIDIAN_MAX }; // ???.
constexpr int		SUM_PARALLEL{ INTERVAL_PARALLEL_MAX + INTERVAL_PARALLEL_MAX }; // ???.

struct Point 
{
	float meridian_pos{};
	float parallel_pos{};
	float x{};
	float y{};
};

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

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float getIntervalMeridian() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	float getIntervalParallel() const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="tiles"></param>
	void setTiles(const int& tiles);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool isValid() const;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	vector<vector<Point>> createMap();

private:

	/// <summary>
	/// Gets radius of generating globe reduced to given scale.
	/// </summary>
	/// <returns> radius of generating globe reduced to given scale. </returns>
	float getR();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="number"></param>
	/// <returns></returns>
	bool isSquareNumber(const unsigned int& number);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="degrees"></param>
	/// <returns></returns>
	double degreesToRadian(const float& degrees);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="parralel_pos"></param>
	/// <returns></returns>
	float getParallelHeightInCMS(const float& parralel_pos);

	unsigned int	rf					{}; // Representative fraction
	float			interval_meridian	{}; // ???
	float			interval_parallel	{};	// ???
	unsigned int	tiles				{};	// ???
	double			sqrtTiles			{}; // ???
	float			r					{};	// Radius of generating globe reduced to given scale
	double			ln10				{}; // The result of the natural logarithm
	bool			valid				{};	// ???
	bool			throuhZero			{}; // ???

	vector<vector<Point>> points;
};

#endif //MERCATORSPROJECTION_H