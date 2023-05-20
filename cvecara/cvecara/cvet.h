#ifndef _cvet_h_
#define _cvet_h_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <String>

using namespace std;

class Cvet {

	string ime;
	int nabavna, prodajna;

public:

	Cvet(string i, int n, int p) : ime(i), nabavna(n), prodajna(p) {}

	inline int dohvNabavnu() const { return nabavna; }
	inline int dohvProdajnu() const { return prodajna; }
	inline int zarada() const { return prodajna - nabavna; }

	friend bool operator==(const Cvet& cvet1, const Cvet& cvet2) { return cvet1.ime == cvet2.ime; }
	friend std::ostream& operator<<(std::ostream& os, const Cvet& i) { return os << i.ime; }

	~Cvet() {}
};

#endif // !_cvet_h_
