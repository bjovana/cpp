#include "cvecara.h"

void Cvecara::sortiraj() {
	buketi* pom = glava;

	while (pom) {
		buketi* provera = pom->sled;

		while (provera) {
			if (provera->buket->izracunajProdajnuCenu() < pom->buket->izracunajProdajnuCenu()) {
				Buket* t = pom->buket; pom->buket = provera->buket; provera->buket = t;
			}
			provera = provera->sled;
		}

		pom = pom->sled;
	}
}

void Cvecara::dodajBuket(Buket b) {
	if (b.izracunajZaradu() < b.izracunajNabavnuCenu() / 5) {
		return;
	}

	buketi* noviBuket = new buketi;

	noviBuket->buket = new Buket(b);
	noviBuket->sled = nullptr;

	if (!glava) glava = noviBuket;
	else rep->sled = noviBuket;

	rep = noviBuket;

	zarada -= b.izracunajNabavnuCenu(); brBuketa++;

	sortiraj();
}

void Cvecara::prodajBuket(int pozicija) {
	if (pozicija > brBuketa)
		return;

	int i = 1;
	buketi* pom = glava, * pret = nullptr;

	while (i < pozicija) {
		pret = pom;
		pom = pom->sled;
		i++;
	}

	if (!pom)
		return;

	zarada += pom->buket->izracunajProdajnuCenu();

	if (pret)
		pret->sled = pom->sled;
	else
		glava = pom->sled;

	delete pom->buket;
	delete pom;

	brBuketa--;

	return;
}

ostream& operator<<(ostream& os, Cvecara const& c) {
	os << "zarada=" << c.zarada << "RSD\n";

	buketi* pom = c.glava;

	while (pom) {
		os << *pom->buket;
		if (pom->sled)
			os << "\n";
		pom = pom->sled;
	}

	return os;
}


