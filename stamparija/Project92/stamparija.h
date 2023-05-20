#ifndef _stamparija_h_
#define _stamparija_h_

#include "slicica.h"

class Stamparija {

	string* nazivi;
	int brNaziva;

public:

	Stamparija(string* n, int b) : nazivi(n), brNaziva(b) {}

	Stamparija(const Stamparija&) = delete;
	Stamparija(Stamparija&&) = delete;

	Stamparija operator=(const Stamparija&) = delete;
	Stamparija operator=(Stamparija&&) = delete;

	Slicica* stampaj(int broj) {
		if (broj > brNaziva)
			return nullptr;

		string naziv = nazivi[broj - 1];
		Slicica* s = new Slicica(naziv, broj);

		return s;
	}

	inline int dohvBrNaziva() const { return brNaziva; }

	~Stamparija() {
		delete[]nazivi;
	}
};

#endif // !_stamparija_h_

/*
Штампарија се ствара са низом назива свих различитих сличица и бројем назива у низу. Могуће је
одштампати нову сличицу на основу задатог броја сличице, тако што се створи и врати сличица са
задатим бројем и именом које се дохвата са позиције која одговара броју сличице у низу назива
сличица. Уколико сличица са задатим бројем не постоји, вратити нулту вредност. Могуће је
дохватити укупан број различитих сличица. Није могуће направити копију штампарије
*/