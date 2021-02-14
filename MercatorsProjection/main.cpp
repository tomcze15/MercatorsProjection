#include <iostream>
#include "MercatorsProjection.h"

using namespace std;

int main()
{
	MercatorsProjection mp;
	mp.setRF(295000000);
	mp.setTiles(25);

	auto map{ mp.createMap() };

	return 0;
}