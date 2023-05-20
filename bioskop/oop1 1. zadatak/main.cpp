#include "straniFilm.h"
#include "domaciFilm.h"

int main() {
	//testiranje klase vreme
	Vreme v1 = Vreme(4, 45);
	Vreme v2 = Vreme(3, 20);

	Vreme v3 = v1 + v2;

	if (v1 > v2)
		cout << "v1 > v2" << endl;
	else
		cout << "v1 < v2" << endl;

	cout << v3 << endl << endl;

	//testiranje klasa lista i film
	Film* f = new DomaciFilm("Montevideo, Bog te video", v1);
	
	cout << "Film pre ocenjivanja: " << *f << endl;

	f->oceniFilm(76);
	f->oceniFilm(97);
	f->oceniFilm(89);
	
	cout << "Film nakon ocenjivanja: " << *f << endl << endl;
	
	StraniFilm* strani = new StraniFilm("Hari Poter i kamen mudrosti", v2, "Velika Britanija", TITLOVAN);

	cout << "Film pre ocenjivanja: " << *strani << endl;

	strani->oceniFilm(89);
	strani->oceniFilm(81);
	strani->oceniFilm(91);

	cout << "Film nakon ocenjivanja: " << *strani << endl;
}

