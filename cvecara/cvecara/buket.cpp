#include "buket.h"

void Buket::operator+=(Cvet c) {
	cvece* noviCvet = new cvece;

	noviCvet->cvet = new Cvet(c);
	noviCvet->sled = nullptr;

	if (!glava) glava = noviCvet;
	else  rep->sled = noviCvet;

	rep = noviCvet;
}

int Buket::izracunajNabavnuCenu() const {
	int rez = 0;
	cvece* pom = glava;

	while (pom) {
		rez += pom->cvet->dohvNabavnu();
		pom = pom->sled;
	}

	return rez;
}

int Buket::izracunajProdajnuCenu() const {
	int rez = 0;
	cvece* pom = glava;

	while (pom) {
		rez += pom->cvet->dohvProdajnu();
		pom = pom->sled;
	}

	return rez;
}

int Buket::izracunajZaradu() const {
	int rez = 0;
	cvece* pom = glava;

	while (pom) {
		rez += pom->cvet->zarada();
		pom = pom->sled;
	}

	return rez;
}

std::ostream& operator<<(std::ostream& os, const Buket& b) {
	cvece* pom = b.glava;
	os << '(';

	while (pom) {
		os << *pom->cvet;
		if (pom->sled) os << ',';
		pom = pom->sled;
	}

	return os << ')' << b.izracunajProdajnuCenu() << "RSD";
}

