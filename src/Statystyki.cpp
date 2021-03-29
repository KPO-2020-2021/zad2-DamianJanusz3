#include "Statystyki.hh"

//metoda odpowiedzialna za wyświetlanie ilości dobrych i złych odpowiedzi
double staty::Podsumowanie (staty score)  {
    double procent=(this->d * 100)/(this->d + this->z);
cout << "Ilosc dobrych odpowiedzi:" << this->d << endl;
cout << "Ilosc zlych odpowiedzi:" << this->z << endl;
cout << "Wynik procentowy poprawnych odpowiedzi:" << procent << "%"<< endl;
return procent;
}