#include "cvecara.h"

int main() {
	//testiranje klase cvet
	Cvet* cvet = new Cvet("lala", 90, 100);
	cout << "Cvet: " << *cvet;
	cout << "\nNabavna cena: " << cvet->dohvNabavnu() << "RSD";
	cout << "\nProdajna cena: " << cvet->dohvProdajnu() << "RSD";
	cout << "\nZarada: " << cvet->zarada() << "RSD";


	Cvet* jednaki = new Cvet("lala", 70, 160); //prodaja u drugoj cvecari
	Cvet* razliciti = new Cvet("ruza", 90, 240);

	if (*cvet == *jednaki)
		cout << "\n\nRazlika u zaradi " << *cvet << " u razlicitim cvecarama: " << jednaki->zarada() - cvet->zarada();

	if (!(*cvet == *razliciti))
		cout << "\n" << *cvet << " != " << *razliciti << "\n";

	//testiranje klase buket
	Buket buket1 = Buket();

	buket1 += *cvet;
	buket1 += *jednaki;
	buket1 += *razliciti;

	cout << "\n" << buket1 << "\n";
	cout << "Nabavna cena: " << buket1.izracunajNabavnuCenu() << "RSD\n";
	cout << "Zarada: " << buket1.izracunajZaradu() << "RSD\n\n";

	Buket buket2 = Buket();

	buket2 += *razliciti;
	buket2 += *razliciti;
	buket2 += *razliciti;

	if (buket1 > buket2) cout << buket1 << " > " << buket2 << "\n\n";
	else cout << buket2 << " > " << buket1 << "\n\n";

	Buket buket3 = Buket();

	buket3 += *jednaki;
	buket3 += *razliciti;
	buket3 += *razliciti;
	buket3 += *jednaki;
	buket3 += *cvet;
	buket3 += *cvet;

	//testiranje klase cvecara
	Cvecara cvecara = Cvecara();

	cvecara.dodajBuket(buket2);
	cvecara.dodajBuket(buket1);

	cout << cvecara << "\n\nCvecara nakon dodavanja novog buketa: \n";

	cvecara.dodajBuket(buket3);

	cout << cvecara << "\n\nCvecara nakon uklanjanja buketa: \n";

	cvecara.prodajBuket(1);
	cvecara.prodajBuket(2);

	cout << cvecara << "\n";

	Buket buket4 = Buket();

	buket4 += *cvet;

	cvecara.dodajBuket(buket4); //ovaj buket nece da se doda

	cout << "\n" << cvecara << "\n";
}