#pragma once
#include <cmath>

using namespace std;

template<class T>
class RitkaVektor;

template<class T>
class Vektor
{
public:
	Vektor() {}
	Vektor(int dim);
	Vektor(T* t, int dim);
	Vektor(const Vektor&);
	~Vektor();

	Vektor operator+(const Vektor&);
	Vektor operator-(const Vektor&);
	double operator*(const Vektor&);
	double operator~();
	double operator%(const Vektor&);
	T      operator[](int) const;
	operator RitkaVektor<T>();
	void kiir();
private:
	T* m_t;
	int m_dim;
};

template<class T>
Vektor<T>::operator RitkaVektor<T>()
{
	T* tomb = new T[m_dim];
	int dimenzio = 0;
	for (int i = 0; i < m_dim; ++i)
	{
		if (m_t[i] != 0)
		{
			tomb[dimenzio] = m_t[i];
			dimenzio++;
		}
	}
	return RitkaVektor<T>(tomb, dimenzio);
}

template<class T>
Vektor<T>::Vektor(int dim)
{
	m_dim = dim;
	m_t = new T[m_dim];
	for (int i = 0; i < m_dim; ++i)
	{
		m_t[i] = 1;
	}
}

template<class T>
Vektor<T>::Vektor(T* t, int dim)
{
	m_dim = dim;
	m_t = new T[m_dim];
	for (int i = 0; i < m_dim; ++i)
	{
		m_t[i] = t[i];
	}
}

template<class T>
Vektor<T>::Vektor(const Vektor& v)
{
	m_dim = v.m_dim;
	m_t = new T[m_dim];
	for (int i = 0; i < m_dim; ++i)
	{
		m_t[i] = v.m_t[i];
	}
}

template<class T>
Vektor<T>::~Vektor()
{
	delete[] m_t;
}

template<class T>
Vektor<T>Vektor<T>::operator+(const Vektor& v)
{
	if (m_dim != v.m_dim)
		throw("Nem egyezik meg a dimezio!");
	Vektor osszeg(m_t, m_dim);
	for (int i = 0; i < m_dim; ++i)
	{
		osszeg.m_t[i] = m_t[i] + v.m_t[i];
	}
	return osszeg;
}

template<class T>
Vektor<T>Vektor<T>::operator-(const Vektor& v)
{
	if (m_dim != v.m_dim)
		throw("Nem egyezik meg a dimezio!");
	Vektor kulonbseg(m_t, m_dim);
	for (int i = 0; i < m_dim; ++i)
	{
		kulonbseg.m_t[i] = m_t[i] - v.m_t[i];
	}
	return kulonbseg;
}

template<class T>
double Vektor<T>::operator*(const Vektor& v)
{
	//skalaris szorzat
	if (m_dim != v.m_dim)
		throw("Nem egyezik meg a dimezio!");
	double  a = 0;
	for (int i = 0; i < m_dim; ++i)
	{
		a += m_t[i] * v.m_t[i];
	}
	return a;
}

template <class T>
double Vektor<T>::operator~()
{
	//euklideszi norma
	T osszeg = 0;
	double gyok;
	for (int i = 0; i < m_dim; ++i)
	{
		osszeg += m_t[i] * m_t[i];
	}
	gyok = sqrt(osszeg);
	return gyok;
}

template <class T>
double Vektor<T>::operator%(const Vektor& v)
{
	//euklideszi tavolsag
	T a = 0;
	double gyok;
	if (m_dim != v.m_dim)
		throw("Nem egyezik meg a dimezio!");
	for (int i = 0; i < m_dim; ++i)
	{
		a += (m_t[i] - v.m_t[i]) * (m_t[i] - v.m_t[i]);
	}
	gyok = sqrt(a);
	return gyok;
}

template<class T>
T Vektor<T>::operator[](int i) const
{
	return m_t[i];
}

template<class T>
void Vektor<T>::kiir()
{
	for (int i = 0; i < m_dim; ++i)
	{
		cout << m_t[i] << ' ';
	}
	cout << endl;
}