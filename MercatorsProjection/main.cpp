#include <iostream>
#include "MercatorsProjection.h"

using namespace std;

int main()
{
	MercatorsProjection mp;
	mp.setRF(290000000);
	mp.setTiles(49);

	auto map{ mp.createMap() };

	return 0;
}