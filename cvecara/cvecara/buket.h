#ifndef _buket_h
#define _buket_h

#include "cvet.h"

struct cvece {
	Cvet* cvet;
	cvece* sled;
};

class Buket {

	cvece* glava = nullptr, * rep = nullptr;

public:

	Buket() {}

	void operator+=(Cvet c);
	friend ostream& operator<<(ostream& os, Buket const& b);

	friend bool operator>(const Buket& b1, const Buket& b2) { return b1.izracunajProdajnuCenu() > b2.izracunajProdajnuCenu(); }

	int izracunajNabavnuCenu() const;
	int izracunajProdajnuCenu() const;
	int izracunajZaradu() const;

};

#endif // !_buket_h 

