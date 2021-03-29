#include "LZespolona.hh"
#include <math.h>

#define MIN_DIFF 0.01

//funkcja wyświetlająca liczbę zespoloną
void LZespolona::Wyswietl1(LZespolona Skl1) const{

cout<<"("<<this->re<<showpos<<this->im<<noshowpos<<"i"<<")";
}


/* operator do obsługi wyświetlania*/
ostream&operator << (ostream&StrmWy, LZespolona LiczbaWy) {
  StrmWy.precision(2);
  return StrmWy << "(" << std::fixed << LiczbaWy.re << std::showpos << LiczbaWy.im<< std::noshowpos << "i"<<')';
}

/*operator do wczytywania, pochodzi z materiałów zaprezentowanych 
na zajęciach*/
istream& operator >> (istream&StrmWej, LZespolona&LiczbaWe)  {

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

bool  LZespolona::operator == (LZespolona  Skl2) const {
  //if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
  //  return true;
  //else
  //  return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  
  if (abs(this->re - Skl2.re) <= MIN_DIFF && abs(this->im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2) const {
  LZespolona  Wynik;

  Wynik.re = Skl2.re + this->re;
  Wynik.im = Skl2.im + this->im;
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
LZespolona  LZespolona::operator - ( LZespolona Skl2) const
{
  LZespolona Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
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
LZespolona  LZespolona::operator / (  double  Skl2) const{
  if (Skl2==0) {
    throw std::runtime_error("proba dzielenia przez zero");
  }
  LZespolona  Wynik;

  Wynik.re = this->re / Skl2;
  Wynik.im = this->im / Skl2;
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
LZespolona  LZespolona::operator * (  LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->re * Skl2.im + Skl2.re * this->im;
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
LZespolona  LZespolona::operator / ( LZespolona  Skl2) const {

  if (Skl2.re==0 && Skl2.im==0) {
    throw std::runtime_error("Proba dzielenia przez zero");
  }
  LZespolona  Wynik;
  
  Skl2.Sprzezenie(Skl2);

  if(Skl2.im!=0) {                  //czyli jeśli dzielnik nie jest skalarem
    
    Wynik.re = ((this->re * Skl2.re) - (this->im * Skl2.im))/Skl2.Modulkwadrat(Skl2);
    Wynik.im = (this->re * Skl2.im + Skl2.re * this->im)/Skl2.Modulkwadrat(Skl2);
    return Wynik;
    
  }
  else {              //kiedy dzielnik jest skalarem
  Wynik.re = this->re / Skl2.re;
  Wynik.im = this->im / Skl2.re;
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
LZespolona  LZespolona::Sprzezenie (LZespolona  &Skl2) 
{
  this->im = (-1 * this->im);
  return Skl2;
}

/*!
 * Realizuje wyliczanie kwadratu modulu.
 * Argumenty:
 *    Skl1 - dana liczba zespolona,
 *    
 * Zwraca:
 *    wartość kwadratu modulu liczby zespolonej.
 */
double LZespolona::Modulkwadrat (LZespolona  Skl2) const
{
  double Wynik;

  Wynik = pow(this->re, 2) + pow(this->im,2);
  
  return Wynik;
}

LZespolona operator += (LZespolona &Skl1, LZespolona const &Skl2) {
  Skl1=Skl1+Skl2;

return Skl1;
}

LZespolona operator /= (LZespolona &Skl1, LZespolona const &Skl2) {
  
  Skl1=Skl1/Skl2;

  return Skl1;
}

 double LZespolona::arg(LZespolona z)const {
   double fi;
   int q=2;
   if (this->re == 0) {
     if(this->im > 0) {
       fi=M_PI/2;
     }
     else if(this->im < 0) {
       fi=-M_PI/2;
     }
     else {
       throw std::runtime_error("argument jest nieokreślony");
       }
   }
   else  {
     if (this->re > 0) {
       fi=atan2(this->im, this->re);
     }
    if (this->re < 0) {
      fi=atan2(this->im, this->re) + M_PI;
    }
   }
   cout << fi;
   double x=fi*pow(10,q);
   if ( x - floor(x) < 0.5 )
        x = floor(x);
    else
        x = floor(fi)+1;
   return x/pow(10,q);
        
 }