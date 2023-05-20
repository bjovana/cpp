#ifndef _greske_h_
#define _greske_h_

#include <iostream>
#include <exception>

using namespace std;

class GVanOpsega : public exception {
public:
	GVanOpsega() :exception("*** Indeks van opsega! ***") {}
};

#endif // !_greske_h_
