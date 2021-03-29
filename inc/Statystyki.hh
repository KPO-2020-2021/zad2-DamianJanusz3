#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include<iostream>
using namespace std;

//struktura do operowania statystykami
struct staty {
    int d;         //ilość dobrych odpowiedzi
    int z;          //ilość złych odpowiedzi

   double Podsumowanie (staty score) ;      //double tylko na potrzeby testów bo nie miałem lepszego pomysłu
};



#endif
