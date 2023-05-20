#ifndef _spil_h_
#define _spil_h_

#include "stamparija.h"

struct slicice {
	Slicica* slicica;
	struct slicice* sled;
};

class Spil {

	slicice* glava = nullptr, * rep = nullptr, * tekuca = nullptr;

public:

	Spil() {}

	Spil(const Spil&) = delete;
	Spil(Spil&&) = delete;

	Spil operator=(const Spil&) = delete;
	Spil operator=(Spil&&) = delete;

	void operator+=(Slicica* s);
	bool operator%(int br);

	Slicica* izvadiSlicicu(int br);

	void postaviNaPrvu() { tekuca = glava; }
	
	void pomeriNaNaredno() {
		if (tekuca) tekuca = tekuca->sled;
	}

	inline bool provera() const { return tekuca != nullptr; }
	
	Slicica* dohvSaTekuce() const {
		if (tekuca) return tekuca->slicica;
	}

	friend std::ostream& operator << (std::ostream& os, const Spil& t) {
		slicice* pom = t.glava;

		while (pom) {
			os << *pom->slicica;
			if (pom->sled) os << endl;
			pom = pom->sled;
		}

		return os;
	}

	~Spil();
};

#endif // !_spil_h_

