#include <iostream>
#include "MercatorsProjection.h"

using namespace std;

int main()
{
	MercatorsProjection mp;
	mp.setRF(295000000);
	mp.setTiles(25);

	if (mp.isValid())
		cout << "Bledny dane, aby utworzyæ zrzut!" << endl;

	auto map{ mp.createMap() };

	return 0;
}