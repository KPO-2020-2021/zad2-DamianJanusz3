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

  LZespolona  Sprzezenie (LZespolona  &Skl2) ;

  double Modulkwadrat (LZespolona  Skl2) const ;

  LZespolona operator + (  LZespolona  Skl2)const;

  LZespolona operator - ( LZespolona  Skl2)const;

  LZespolona operator / (double Skl2)const;

  LZespolona  operator * ( LZespolona  Skl2)const;

  LZespolona  operator / (  LZespolona  Skl2)const;

  bool  operator == ( LZespolona  Skl2)const;

  void Wyswietl1(LZespolona Skl1)const;

  friend istream& operator >> (istream&StrmWej, LZespolona&LiczbaWe);

  friend ostream & operator << (ostream&StrmWy, LZespolona LiczbaWy);

  friend LZespolona operator += (LZespolona &Skl1, LZespolona const &Skl2);

  friend LZespolona operator /= (LZespolona &Skl1, LZespolona const &Skl2);

  double arg(LZespolona z)const;
};

#endif
