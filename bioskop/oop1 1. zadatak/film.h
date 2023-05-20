#ifndef _film_h_
#define _film_h_

#include "lista.h"
#include "vreme.h"
#include <string>

class Film {
private:

	Lista <int> ocene = Lista<int>();

protected:
	string naziv;
	Vreme trajanje;

public:
	Film(string n, Vreme t):naziv(n), trajanje(t){}
	void oceniFilm(int ocena) { ocene += ocena; }
	Vreme dohvTrajanje() const { return trajanje; }

	float dohvProsecnuOcenu() const {
		try {
			float prosek = 0.0;

			for (int i = 0; i < ocene.dohvBrPodataka(); i++)
				prosek += ocene.dohvSaPozicije(i);

			if (prosek == 0.0)
				return 0.0;
			return prosek / ocene.dohvBrPodataka();
		}
		catch (GVanOpsega g) {
			cout << g.what();
			return 0.0;
		}
	}

	virtual char dohvatiJednoslovnuOznaku() const = 0;
	friend ostream& operator<<(ostream& os, const Film& f) {
		return os << f.dohvatiJednoslovnuOznaku() << " " << f.naziv << " " << f.trajanje << " " << f.dohvProsecnuOcenu();
	}
};

#endif // !_film_h_



