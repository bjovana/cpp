#ifndef _straniFilm_h_
#define _straniFilm_h_

#include "film.h"

enum  Prevod {
	TITLOVAN,
	SINHRONIZOVAN
};

class StraniFilm : public Film {
private:
	string zemlja;
	Prevod tip;

public:
	StraniFilm(string naziv, Vreme trajanje, string z, Prevod p) : Film(naziv, trajanje),  zemlja(z), tip(p) {}
	char dohvatiJednoslovnuOznaku() const override { return 'S'; }

	friend ostream& operator<<(ostream& os, StraniFilm& sf) {
		string s;

		if (sf.tip == TITLOVAN) s += "TITLOVAN";
		else s += "SINHRONIZOVAN";

		return os << sf.dohvatiJednoslovnuOznaku() << " " << sf.naziv << " " << sf.trajanje << " " << sf.dohvProsecnuOcenu() << " " << sf.zemlja << " " << s;
	}
};

#endif // !_straniFilm_h_
