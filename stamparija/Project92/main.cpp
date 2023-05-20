#include "spil.h"

int main() {

	//testiranje klasa stamparija i slicica
	string* pokemoni = new string[4];
	
	pokemoni[0] = "pikacu";
	pokemoni[1] = "ponita";
	pokemoni[2] = "bubasaur";
	pokemoni[3] = "mjutu";

	Stamparija * leptiric = new Stamparija(pokemoni, 4);

	Slicica* s1 = leptiric->stampaj(3);
	Slicica* s2 = leptiric->stampaj(4);
	Slicica* s3 = leptiric->stampaj(1);
	Slicica* s4 = leptiric->stampaj(2);

	cout << "Slicice:" << endl;
	cout << *s1 << endl;
	cout << *s2 << endl;
	cout << *s3 << endl;
	cout << *s4 << endl << endl;

	//testiranje spila
	Spil* spil = new Spil();

	*spil += s3;
	*spil += s1;
	*spil += s2;
	*spil += s4;

	cout << "Kreirani spil:" << endl;
	cout << *spil << endl << endl;

	spil->izvadiSlicicu(3); //ova slicica ce se ukloniti
	spil->izvadiSlicicu(11); //ova vec nije u spilu

	cout << "Spil nakon uklanjanja slicica:" << endl;
	cout << *spil << endl << endl;

	spil->postaviNaPrvu();
	spil->pomeriNaNaredno();

	Slicica* tekucaSlicica = spil->dohvSaTekuce();
	if (tekucaSlicica) cout << "Slicica na tekucoj poziciji: " << *tekucaSlicica << endl;
}

/*
Шпил садржи произвољан број сличица. Ствара се празан, након чега се сличице појединачно додају
(spil+=slicica). Могуће је проверити да ли се у шпилу налази сличица са задатим бројем
(spil%broj). Могуће је текућу позицију у шпилу поставити на место прве сличице и померити је на
наредно место у шпилу. Могуће је проверити да ли се на текућој позицији налази сличица или се
дошло до краја шпила, као и дохватити сличицу са тренутне позиције. Из шпила је могуће извадити
сличицу са задатим бројем. Није могуће направити копију шпила. Могуће је исписати шпил у излазни
ток (it<<spil) тако што се свака сличица испише у засебном реду.
*/