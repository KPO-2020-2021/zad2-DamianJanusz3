#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;




int main(int argc, char **argv)
{
  


  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;



  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona wynik, wpisana;
  int i;
  staty wyn; wyn.d=0; wyn.z=0;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    if (WyrZ_PytanieTestowe.Arg2.re==0 && WyrZ_PytanieTestowe.Arg2.im==0){
      cerr<< "Błąd, próba dzielenia przez zero"<< endl;
    }
    else {
    cout << " Podaj wartość wyrażenia: ";
    
    Wyswietl(WyrZ_PytanieTestowe);
    wynik=Oblicz(WyrZ_PytanieTestowe);
    cout << wynik<<endl;
    cin >> wpisana;
    if (cin.fail()==true) {
    for ( i=0; (cin.fail()==true && i<=1); i++){
    cin.clear();
    cin.ignore(99999,'\n');
    cout << "Błędny sposób zapisu spróbuj jeszcze raz!"<< endl;
    cin >> wpisana;
    }
    }
    cin.clear();
    cin.ignore(99999,'\n');
    if (wynik==wpisana) {
      wyn.d++;
      cout << "Prawidłowo!" << endl;
    }
    else {
      wyn.z++;
      cout << "Błąd, poprawna odpowiedź to:" << wynik << endl;
    }
    
    }

    
  }

  Podsumowanie(wyn);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
