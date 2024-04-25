#pragma once
#include "Vektor.h"
#include <cmath>

template < class T >
struct nonZero
{
	T elem;
	int index;
};

template<class T>
class RitkaVektor
{
public:
	operator Vektor<T>();
	RitkaVektor() {}
	RitkaVektor(int _dim);
	RitkaVektor(T* t, int _dim);
	RitkaVektor(const RitkaVektor&);
	~RitkaVektor();

	RitkaVektor operator+(const RitkaVektor&);
	RitkaVektor operator-(const RitkaVektor&);
	double operator*(const RitkaVektor&);
	double operator~();
	double operator%(const RitkaVektor&);
	T      operator[](int) const;
	void kiir();
private:
	nonZero <T>* vektor;
	int nZeroDim;
	int dim;
};

template<class T>
RitkaVektor<T>::operator Vektor<T>()
{
	T* tomb = new T[nZeroDim];
	for (int i = 0; i < nZeroDim; ++i)
	{
		tomb[i] = vektor[i].elem;
	}
	return Vektor<T>(tomb, nZeroDim);
}

template<class T>
RitkaVektor<T>::RitkaVektor(int _dim)
{
	dim = _dim;
	vektor = new nonZero<T>[dim];
	vektor[0].elem = 1;
	nZeroDim = 1;
	for (int i = 1; i < dim; ++i)
	{
		vektor[i].elem = 0;
	}
}

template<class T>
RitkaVektor<T>::RitkaVektor(T* t, int _dim)
{
	dim = _dim;
	nZeroDim = 0;
	vektor = new nonZero<T>[dim];
	for (int i = 0; i < dim; ++i)
	{
		if (t[i] != 0)
		{
			vektor[nZeroDim].elem = t[i];
			vektor[nZeroDim].index = i;
			nZeroDim++;
		}
	}
}

template <class T>
RitkaVektor<T>::RitkaVektor(const RitkaVektor& v)
{
	dim = v.dim;
	nZeroDim = v.nZeroDim;
	int j = 0;
	vektor = new nonZero<T>[nZeroDim];
	for (int i = 0; i < v.nZeroDim; ++i)
	{
		vektor[j].elem = v.vektor[i].elem;
		vektor[j].index = v.vektor[i].index;
		j++;
	}
}

template<class T>
RitkaVektor<T>RitkaVektor<T>::operator+(const RitkaVektor& v)
{
	if (nZeroDim != v.nZeroDim)
		throw("Nem egyezik meg a dimezio!");
	T* ossz = new T[dim];
	int j = 0;
	for (int i = 0; i < dim; i++)
	{
		if (i == vektor[j].index)
		{
			ossz[i] = vektor[j].elem;
			j++;
		}
		else ossz[i] = 0;
	}
	for (int i = 0; i < v.nZeroDim; ++i)
	{
		int index = v.vektor[i].index;
		ossz[index] += v.vektor[i].elem;
	}
	RitkaVektor eredmeny(ossz, dim);
	return eredmeny;
}

template<class T>
RitkaVektor<T>RitkaVektor<T>::operator-(const RitkaVektor& v)
{
	if (nZeroDim != v.nZeroDim)
		throw("Nem egyezik meg a dimezio!");
	T* kul = new T[dim];
	int j = 0;
	for (int i = 0; i < dim; i++)
	{
		if (i == vektor[j].index)
		{
			kul[i] = vektor[j].elem;
			j++;
		}
		else kul[i] = 0;
	}
	for (int i = 0; i < v.nZeroDim; ++i)
	{
		int index = v.vektor[i].index;
		kul[index] -= v.vektor[i].elem;
	}
	RitkaVektor eredmeny(kul, dim);
	return eredmeny;
}

template<class T>
double RitkaVektor<T>::operator*(const RitkaVektor& v)
{
	//skalaris szorzat
	double sum = 0;
	T* szor = new T[dim];
	int j = 0;
	for (int i = 0; i < dim; i++)
	{
		if (i == vektor[j].index)
		{
			szor[i] = vektor[j].elem;
			j++;
		}
		else szor[i] = 0;
	}
	for (int i = 0; i < v.nZeroDim; i++)
	{
		sum += szor[i] * v.vektor[i].elem;
	}
}

template <class T>
double RitkaVektor<T>::operator~()
{
	//euklideszi norma
	T osszeg = 0;
	double gyok;
	for (int i = 0; i < nZeroDim; ++i)
	{
		osszeg += vektor[i].elem * vektor[i].elem;
	}
	gyok = sqrt(osszeg);
	return gyok;
}

template <class T>
double RitkaVektor<T>::operator%(const RitkaVektor& v)
{
	//euklideszi tavolsag
	T a = 0;
	double gyok;
	if (dim != v.dim)
		throw("Nem egyezik meg a dimezio!");
	for (int i = 0; i < nZeroDim; ++i)
	{
		a += (vektor[i].elem - v.vektor[i].elem) * (vektor[i].elem - v.vektor[i].elem);
	}
	gyok = sqrt(a);
	return gyok;
}

template<class T>
T RitkaVektor<T>::operator[](int i) const
{
	if (i > nZeroDim || i < 0)
		throw("Rossz index!");
	return vektor[i].elem;
}

template<class T>
void RitkaVektor<T>::kiir()
{
	for (int i = 0; i < nZeroDim; ++i)
	{
		cout << vektor[i].elem << ' ';
	}
	cout << endl;
}

template<class T>
RitkaVektor<T>::~RitkaVektor()
{
	delete[] vektor;
}