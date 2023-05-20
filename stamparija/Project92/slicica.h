#ifndef _slicica_h_
#define _slicica_h_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

class Slicica {

	static int stId;
	int broj, id;
	string naziv;

	Slicica(string n, int b) : naziv(n), broj(b), id(++stId) {}

public:

	inline int dohvID() const { return id; }
	inline int dohvBroj() const { return broj; }
	inline string dohvNaziv() const { return naziv; }

	friend class Stamparija;

	Slicica(const Slicica&) = delete;
	Slicica(Slicica&&) = delete;

	Slicica operator=(const Slicica&) = delete;
	Slicica operator=(Slicica&&) = delete;

	friend std::ostream& operator << (std::ostream& os, const Slicica& t) {
		return os << "Slicica " << t.broj << " - " << t.naziv << " (" << t.id << ")";
	}
};

#endif // !_slicica_h

