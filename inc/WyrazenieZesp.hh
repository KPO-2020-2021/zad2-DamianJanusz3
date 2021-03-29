#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
using namespace std;

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel,Op_dodajipodstaw ,Op_dzielipodstaw };




/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  void Wyswietl(WyrazenieZesp  WyrZ);

  LZespolona Oblicz(WyrazenieZesp  WyrZ);

  friend ostream&operator << (ostream&StrmWy, WyrazenieZesp WyrZ);

  friend istream& operator >> (istream&StrmWej, WyrazenieZesp&WyrZ);
};

#endif
