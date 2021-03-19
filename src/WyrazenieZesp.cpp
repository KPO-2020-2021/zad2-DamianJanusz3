#include "WyrazenieZesp.hh"




/*
 Wyświetlanie wyrażenia zespolonego
 */
void Wyswietl(WyrazenieZesp  WyrZ) {
if (WyrZ.Op== Op_Dodaj)
    cout << WyrZ.Arg1 << " " << "+" << " " << WyrZ.Arg2<< endl;
else if (WyrZ.Op==Op_Odejmij)
    cout << WyrZ.Arg1 << " " << "-" << " " << WyrZ.Arg2<< endl;
else if (WyrZ.Op==Op_Mnoz)
    cout << WyrZ.Arg1 << " " << "*" << " " << WyrZ.Arg2<< endl;
else if (WyrZ.Op==Op_Dziel)
    cout << WyrZ.Arg1 << " " << "/" << " " << WyrZ.Arg2<< endl;
}



/* Obliczanie wyrażenia zespolonego*/
LZespolona Oblicz(WyrazenieZesp WyrZ) {
 switch(WyrZ.Op){
case Op_Dodaj:
    return WyrZ.Arg1 + WyrZ.Arg2;
    break;

case Op_Odejmij:
    return WyrZ.Arg1 - WyrZ.Arg2;
    break;

case Op_Mnoz:
    return WyrZ.Arg1 * WyrZ.Arg2;
    break;

case Op_Dziel:
   
    return WyrZ.Arg1 / WyrZ.Arg2;
    break;

default: {
return WyrZ.Arg1;}
 }
    
}


//ostream&operator << (ostream&StrmWy, WyrazenieZesp WyrZ)

//istream& operator >> (istream&StrmWej, WyrazenieZesp&WyrZ)
