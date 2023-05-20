#ifndef _vreme_h_
#define _vreme_h_

#include <iostream>
#include <format>


using namespace std;

class Vreme {
private:
	int sati, minuti;

public:
	Vreme(int sati, int minuti) { this->sati = sati; this->minuti = minuti; }
	
	friend bool operator>(Vreme v1, Vreme v2) { 
		return (v1.sati > v2.sati) or (v1.sati == v2.sati and v1.minuti > v2.minuti);
	}

	friend Vreme& operator+(Vreme v1, Vreme v2) {
		int noviSati = v1.sati + v2.sati;
		int noviMin = v1.minuti + v2.minuti;
		if (noviMin > 59) {
			noviMin -= 60;
			noviSati += 1;
		}
		Vreme v = Vreme(noviSati, noviMin);
		return v;
	}

	friend ostream& operator<<(std::ostream& os, const Vreme& v) { 
		if (v.sati < 10) os << "0";
		os << v.sati << ":";
		if (v.minuti < 10) os << "0";
		return os << v.minuti;
	}

	~Vreme() {}
};

#endif // !_vreme_h_

