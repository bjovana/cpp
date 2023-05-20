#ifndef _cvecara_h_
#define _cvecara_h_

#include "buket.h"

using namespace std;

struct buketi {
	Buket* buket;
	buketi* sled;
};

class Cvecara {

	buketi* glava = nullptr, * rep = nullptr;
	int zarada = 1000, brBuketa = 0;

	void sortiraj();

public:

	Cvecara() {}

	void dodajBuket(Buket b);
	void prodajBuket(int pozicija);

	friend ostream& operator<<(ostream& os, Cvecara const& c);

	~Cvecara() {
		while (glava) {
			buketi* pom = glava;
			glava = glava->sled;
			delete pom->buket;
			delete pom;
		}
	}

};

#endif // !_cvecara_h_

