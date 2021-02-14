#ifndef MERCATORSPROJECTION_H
#define MERCATORSPROJECTION_H
#include <vector>

using namespace std;

#pragma region Globale_Parameters

constexpr float		RADIUS_OF_EARTH{		637100000.f	};							// Radius of earth.
constexpr int		INTERVAL_MERIDIAN_MAX{	180			};							// Longitude.
constexpr int		INTERVAL_PARALLEL_MAX{	80			};							// Latitude.
constexpr int		SUM_MERIDIAN{ INTERVAL_MERIDIAN_MAX + INTERVAL_MERIDIAN_MAX };	// Sum Longitude.
constexpr int		SUM_PARALLEL{ INTERVAL_PARALLEL_MAX + INTERVAL_PARALLEL_MAX };	// Sum Latitude.

#pragma endregion

/// <summary>
/// Point information about intersection of the meridian and the parallel and position in centimeters.
/// </summary>
struct Point 
{
	float meridian_pos{};	// The current meridian degree.
	float parallel_pos{};	// The current parallel degree.
	float x{};				// Position x on map in centimeters.
	float y{};				// Position y on map in centimeters.
};

/// <summary>
/// Creates a mercator projection based on the scale and number of tiles.
/// </summary>
class MercatorsProjection
{
public:

	/// <summary>
	/// Takes two optional values representative fraction and number of tiles.
	/// </summary>
	/// <param name="rf">is representative fraction.</param>
	/// <param name="tiles"> determines how many elements the consists of map.</param>
	MercatorsProjection(unsigned rf = 1, unsigned tiles = 4);

	~MercatorsProjection();

#pragma region Public_Functions

	/// <summary>
	/// Sets representative fraction in centimeters.
	/// </summary>
	/// <param name="rf"> - is representative fraction in centimeters.</param>
	void setRF(const unsigned& rf);

	/// <summary>
	/// Sets how many tiles consisted of the map.
	/// Tiles have to be a square number.
	/// </summary>
	/// <param name="tiles"> - Number of map elements.</param>
	void setTiles(const int& tiles);

	/// <summary>
	/// Gets the current representative fraction.
	/// </summary>
	/// <returns> Representative fraction in centimeters. </returns>
	unsigned getRF() const;

	/// <summary>
	/// Gets a value in degrees of how far apart the meridians are.
	/// </summary>
	/// <returns>Width in degrees.</returns>
	float getIntervalMeridian() const;
	
	/// <summary>
	/// Gets a value in degrees of how far apart the parallels are.
	/// </summary>
	/// <returns>Height in degrees.</returns>
	float getIntervalParallel() const;

	/// <summary>
	/// Gets value:
	/// <para>True - is something wrong like bad tiles value.</para>
	/// <para>False - is everthing okey.</para>
	/// </summary>
	/// <returns>Information about the correctness of the data.</returns>
	bool isValid() const;

	/// <summary>
	/// Gets Mercator map built on points.
	/// </summary>
	/// <returns>Mercator map.</returns>
	vector<vector<Point>> createMap();

#pragma endregion

private:

#pragma region Private_Functions

	/// <summary>
	/// Gets radius of generating globe reduced to given scale.
	/// </summary>
	/// <returns> radius of generating globe reduced to given scale. </returns>
	float getR();

	/// <summary>
	/// Checks if a number is a square number.
	/// </summary>
	/// <param name="number"> - number.</param>
	/// <returns>
	/// <para>True - number is square number.</para>
	/// <para>False - number is not square number.</para>
	/// </returns>
	bool isSquareNumber(const unsigned int& number);

	/// <summary>
	/// Convert degrees to radians.
	/// </summary>
	/// <param name="degrees"> is degrees.</param>
	/// <returns>Radians.</returns>
	double degreesToRadian(const float& degrees);

	/// <summary>
	/// Gets the distance of the parallel from the equator in centimeters.
	/// </summary>
	/// <param name="parralel_pos"> - Parallel degree.</param>
	/// <returns>Distance from the equator in centimeters.</returns>
	float getParallelHeightInCms(const float& parralel_pos);

#pragma endregion

#pragma region Private_Parameters

	unsigned int	rf					{}; // Representative fraction.
	float			interval_meridian	{}; // Actually interval between the meridians.
	float			interval_parallel	{};	// Actually interval between the parallels.
	unsigned int	tiles				{};	// Tiles of map.
	double			sqrtTiles			{}; // Square from number of tiles.
	float			r					{};	// Radius of generating globe reduced to given scale.
	double			ln10				{}; // The result of the natural logarithm.
	bool			valid				{};	// Flag data validation.
	bool			throuhZero			{}; // Flag about the parallel passes through the equator.

#pragma endregion
};

#endif //MERCATORSPROJECTION_H