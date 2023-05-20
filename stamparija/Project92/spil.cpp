#include "spil.h"

void Spil::operator+=(Slicica* s) {
	slicice* nova = new slicice;
	
	nova->slicica = s;
	nova->sled = nullptr;

	if (!glava) glava = nova;
	else rep->sled = nova;

	rep = nova;
}

bool Spil::operator%(int br) {
	slicice* pom = glava;

	while (pom) {
		if (pom->slicica->dohvBroj() == br) return true;
		pom = pom->sled;
	}

	return false;
}

Slicica* Spil::izvadiSlicicu(int br) {
	if (!(*this % br))
		return nullptr;

	slicice* pom = glava, * pret = nullptr;
	while (pom->slicica->dohvBroj() != br) {
		pret = pom; pom = pom->sled;
	}

	if (pret) pret->sled = pom->sled;
	else glava = glava->sled;

	delete pom->slicica;
	delete pom;
}

Spil::~Spil()
{
	slicice* pom;
	while (glava != nullptr) {
		pom = glava;
		glava = glava->sled;
		delete(pom->slicica);
		delete(pom);
	}
}
