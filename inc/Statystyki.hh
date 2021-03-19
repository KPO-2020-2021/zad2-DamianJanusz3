#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include<iostream>
using namespace std;

//struktura do operowania statystykami
struct staty {
    int d;         //ilość dobrych odpowiedzi
    int z;          //ilość złych odpowiedzi
};

void Podsumowanie (staty score);

#endif
