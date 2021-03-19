#include "Statystyki.hh"

//funkcja odpowiedzialna za wyświetlanie ilości dobrych i złych odpowiedzi
void Podsumowanie (staty score) {
    double procent=(score.d * 100)/(score.d + score.z);
cout << "Ilosc dobrych odpowiedzi:" << score.d << endl;
cout << "Ilosc zlych odpowiedzi:" << score.z << endl;
cout << "Wynik procentowy poprawnych odpowiedzi:" << procent << "%"<< endl;
}