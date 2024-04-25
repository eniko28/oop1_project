#include <iostream>
#include "Vektor.h"
#include "RitkaVektor.h"

using namespace std;

int main()
{
	int a[] = {1, 1, 3, 1 };
	int b[] = { 0, 1, 0, 1 };

	Vektor<int> W(a, 4);
	Vektor<int> U(b, 4);

	/*RitkaVektor<int> W = V;
	RitkaVektor<int> U = S;*/

	try {
		(W + U).kiir();
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	try {
		(W - U).kiir();
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	try {
		cout << "a W es U vektor  skalaris szorzata = " << W * U << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << "a W vektor euklideszi normaja = " << ~W << endl;
	cout << "az U vektor euklideszi normaja = " << ~U << endl;
	try {
		cout << "a W es U vektorok euklideszi tavolsaga = " << W % U << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	try {
		cout << "a W vektor 3. eleme: " << W[2] << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	try {
		cout << "az U vektor 1. eleme: " << U[0] << endl;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	return 0;
}