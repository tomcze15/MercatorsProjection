#include <iostream>
#include "MercatorsProjection.h"

using namespace std;

int main()
{
	MercatorsProjection mp;
	mp.setRF(210000000);
	mp.setTiles(9);

	auto map{ mp.createMap() };

	return 0;
}