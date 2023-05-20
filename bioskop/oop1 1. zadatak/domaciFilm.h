#ifndef _domaciFilm_h_
#define _domaciFilm_h

#include "film.h"

class DomaciFilm : public Film {
public:
	DomaciFilm(string naziv, Vreme trajanje) : Film(naziv,trajanje) {}
	char dohvatiJednoslovnuOznaku() const override { return 'D'; }
};

#endif // !_domaciFilm_h_

