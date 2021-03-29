#include "WyrazenieZesp.hh"




/*
 Wyświetlanie wyrażenia zespolonego
 */
void WyrazenieZesp::Wyswietl(WyrazenieZesp  WyrZ) {
if (this->Op== Op_Dodaj)
    cout << this->Arg1 << " " << "+" << " " << this->Arg2<< endl;
else if (this->Op==Op_Odejmij)
    cout << this->Arg1 << " " << "-" << " " << this->Arg2<< endl;
else if (this->Op==Op_Mnoz)
    cout << this->Arg1 << " " << "*" << " " << this->Arg2<< endl;
else if (this->Op==Op_Dziel)
    cout << this->Arg1 << " " << "/" << " " << this->Arg2<< endl;
else if (this->Op==Op_dodajipodstaw)
    cout << this->Arg1 << " " << "+=" << " " << this->Arg2<< endl;
else if (this->Op==Op_dzielipodstaw)
    cout << this->Arg1 << " " << "/=" << " " << this->Arg2<< endl;
}



/* Obliczanie wyrażenia zespolonego*/
LZespolona WyrazenieZesp::Oblicz(WyrazenieZesp WyrZ) {
 switch(this->Op){
case Op_Dodaj:
    return this->Arg1 + this->Arg2;
    break;

case Op_Odejmij:
    return this->Arg1 - this->Arg2;
    break;

case Op_Mnoz:
    return this->Arg1 * this->Arg2;
    break;

case Op_Dziel:
   
    return this->Arg1 / this->Arg2;
    break;

case Op_dodajipodstaw:
    return this->Arg1 += this->Arg2;
    break;

case Op_dzielipodstaw:
    return this->Arg1 /= this->Arg2;
    break;

default: 
    throw std::runtime_error("nierozpoznany operator");
    
}
}


ostream&operator << (ostream&StrmWy, WyrazenieZesp WyrZ) {
    StrmWy.precision(2);
if (WyrZ.Op== Op_Dodaj) 
    return StrmWy << std::fixed << WyrZ.Arg1 <<" + "<< std::fixed << WyrZ.Arg2; 
else if (WyrZ.Op==Op_Odejmij)
    return StrmWy << std::fixed << WyrZ.Arg1 <<" - "<< std::fixed << WyrZ.Arg2;
else if (WyrZ.Op==Op_Mnoz)
    return StrmWy << std::fixed << WyrZ.Arg1 <<" * "<< std::fixed << WyrZ.Arg2;
else if (WyrZ.Op==Op_Dziel)
    return StrmWy << std::fixed << WyrZ.Arg1 <<" / "<< std::fixed << WyrZ.Arg2;
else if (WyrZ.Op==Op_dodajipodstaw)
    return StrmWy << std::fixed << WyrZ.Arg1 <<" += "<< std::fixed << WyrZ.Arg2;
else if (WyrZ.Op==Op_dzielipodstaw)
    return StrmWy << std::fixed << WyrZ.Arg1 <<" /= "<< std::fixed << WyrZ.Arg2;
    else return StrmWy <<"nie udalo sie wyswietlic" << endl;
}


istream& operator >> (istream&StrmWej, WyrazenieZesp&WyrZ) {

  char znak;
  if (StrmWej.fail())
  return StrmWej;
  
  StrmWej >> WyrZ.Arg1;
  if (StrmWej.fail())
  return StrmWej;
  StrmWej >> znak;
  if (StrmWej.fail())
  return StrmWej;
  if (znak != '+' /*||znak != '-' || znak != '*' || znak != '/' *//*|| znak != '+=' || znak != '/='*/) {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
  }
  StrmWej >> WyrZ.Arg2;
  if (StrmWej.fail())
  return StrmWej;

  return StrmWej;
}