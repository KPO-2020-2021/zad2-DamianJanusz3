#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>
using namespace std;



/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

void Wyswietl1(LZespolona Skl1);    
/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */
ostream & operator << (ostream&StrmWy, LZespolona LiczbaWy);

istream& operator >> (istream&StrmWej, LZespolona&LiczbaWe);

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator / (LZespolona Skl1, double Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  Sprzezenie (LZespolona  Skl2);

double Modulkwadrat (LZespolona  Skl2);

#endif
