#ifndef _lista_h_
#define _lista_h_

#include "greske.h"

template<typename T>
class Lista {
private:
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr) {
			pod = p;
			sled = s;
		}
	};
	Elem* prvi, * poslednji;
	mutable Elem* tekuci;
	int trenutno;

	void kopiraj(const Lista& l);
	void premesti(Lista& l) {
		prvi = l.prvi;
		poslednji = l.poslednji;
		l.prvi = l.poslednji = nullptr;
		trenutno = l.trenutno;
	}
	void isprazni();

public:
	Lista() { prvi = poslednji = tekuci = nullptr; trenutno = 0; }

	Lista(const Lista& l) {
		kopiraj(l);
	}

	Lista(Lista&& l) {
		premesti(l);
	}

	~Lista() {
		isprazni();
	}

	Lista& operator=(const Lista& l) {
		if (this != &l) {
			isprazni();
			kopiraj(l);
		}
		return *this;
	}

	Lista& operator=(Lista&& l) {
		if (this != &l) {
			isprazni();
			premesti(l);
		}
		return *this;
	}
	
	void operator+= (const T& p) {
		poslednji = (!prvi ? prvi : poslednji->sled) = new Elem(p);
		trenutno++;
	}

	int dohvBrPodataka() const { return trenutno; }

	T& dohvSaPozicije(int pozicija) const {
		if (pozicija >= trenutno or pozicija < 0) throw GVanOpsega();
		
		tekuci = prvi;
		for (int i = 0; i < trenutno; i++) {
			if (i == pozicija) { return tekuci->pod; }
			tekuci = tekuci->sled;
		}
	}
};

template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = poslednji = tekuci = nullptr;

	for (Elem* pok = l.prvi; pok; pok = pok->sled) {
		Elem* novi = new Elem(pok->pod);
		poslednji = (!prvi ? prvi : poslednji->sled) = novi;
	}

	trenutno = l.trenutno;
}

template<typename T>
void Lista<T>::isprazni() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	poslednji = tekuci = nullptr;
	trenutno = 0;
}

#endif // !_lista_h_

