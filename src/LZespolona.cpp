#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.00001

//funkcja wyświetlająca liczbę zespoloną
void Wyswietl1(LZespolona Skl1) {

cout<<"("<<Skl1.re<<showpos<<Skl1.im<<noshowpos<<"i"<<")";
}


/* operator do obsługi wyświetlania*/
ostream&operator << (ostream&StrmWy, LZespolona LiczbaWy) {

  return StrmWy << "(" << LiczbaWy.re << showpos << LiczbaWy.im<< noshowpos << "i"<<')';
}

/*operator do wczytywania, pochodzi z materiałów zaprezentowanych 
na zajęciach*/
istream& operator >> (istream&StrmWej, LZespolona&LiczbaWe) {

  char Nawias, Litera;
  StrmWej >> Nawias;
  if (StrmWej.fail())
  return StrmWej;
  if (Nawias != '(') {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
  }
  StrmWej >> LiczbaWe.re;
  if (StrmWej.fail())
  return StrmWej;
  StrmWej >> LiczbaWe.im;
  if (StrmWej.fail())
  return StrmWej;
  StrmWej >> Litera;
  if (StrmWej.fail())
  return StrmWej;
  if (Litera != 'i') {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
  }
  StrmWej >> Nawias;
  if (StrmWej.fail())
  return StrmWej;
  if (Nawias != ')') {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
  }
  return StrmWej;
}





/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  
 // if abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF
 //   return true;
 // else
 //   return false;
  
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik liczba od której odejmujemy
 *    Skl2 - drugi skladnik liczba odejmowana
 * Zwraca:
 *    roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



/*!
 * Realizuje dzielenie liczby zespolonej przez skalar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}


/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;
  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  double modul;
  modul = Modulkwadrat(Skl2);
  Skl2 = Sprzezenie(Skl2);

  if(Skl2.im!=0) {                  //czyli jeśli dzielnik nie jest skalarem
    
    Wynik.re = ((Skl1.re * Skl2.re) - (Skl1.im * Skl2.im))/modul;
    Wynik.im = (Skl1.re * Skl2.im + Skl2.re * Skl1.im)/modul;
    return Wynik;
    
  }
  else {              //kiedy dzielnik jest skalarem
  Wynik.re = Skl1.re / Skl2.re;
  Wynik.im = Skl1.im / Skl2.re;
  return Wynik;
  }
}


/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - dana liczba zespolona,
 *    
 * Zwraca:
 *    sprzezenie do podanej liczby zespolonej
 */
LZespolona  Sprzezenie (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl2.re;
  Wynik.im = (-1 * Skl2.im);
  return Wynik;
}

/*!
 * Realizuje wyliczanie kwadratu modulu.
 * Argumenty:
 *    Skl1 - dana liczba zespolona,
 *    
 * Zwraca:
 *    wartość kwadratu modulu liczby zespolonej.
 */
double Modulkwadrat (LZespolona  Skl2)
{
  double Wynik;

  Wynik = sqrt(pow(Skl2.re, 2) + pow(Skl2.im,2));
  
  return Wynik;
}