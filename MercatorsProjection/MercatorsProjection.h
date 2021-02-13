#ifndef MERCATORSPROJECTION_H
#define MERCATORSPROJECTION_H

using namespace std;

constexpr int		RADIUS_OF_EARTH{	637100000	}; // Radius of earth.

class MercatorsProjection
{
public:
	MercatorsProjection();
	//MercatorsProjection(unsigned scale);
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

	unsigned char getInterval() const;

	void setTiles(const int& tiles);

	bool isValid() const;

private:

	/// <summary>
	/// Gets radius of generating globe reduced to given scale.
	/// </summary>
	/// <returns> radius of generating globe reduced to given scale. </returns>
	float getR();

	bool isSquareNumber(const unsigned int& number);

	unsigned int	rf			{}; // Representative fraction
	unsigned char	interval	{};	
	unsigned int	tiles		{};	// ???
	float			r			{};	// Radius of generating globe reduced to given scale
	double			ln10		{}; // The result of the natural logarithm
	bool			valid		{};	// ???
};

#endif //MERCATORSPROJECTION_H