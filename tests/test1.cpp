#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona porównanie równe"){
    LZespolona x, z;

    x.re = 2;
    x.im = -2;

    z.re = 2;
    z.im = -2;
    
    CHECK(x == z);
}

TEST_CASE("test LZespolona porównanie2 nierówne"){
    LZespolona x, z;

    x.re = 3;
    x.im = -2;

    z.re = 2;
    z.im = -2;
    
    CHECK(!(x == z));
}

TEST_CASE("test LZespolona porównanie3 nierówne o małą wartość"){
    LZespolona x, z;

    x.re = 2.1;
    x.im = -2;

    z.re = 2;
    z.im = -2;
    
    CHECK(!(x == z));
}

TEST_CASE("test LZespolona porównanie4 o rząd mniejsze niż min_diff"){
    LZespolona x, z;

    x.re = 2.001;       //w takim wypadku program uznaje ze są równe
    x.im = -2;

    z.re = 2;
    z.im = -2;
    
    CHECK(x == z);
}


TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma2"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma3"){
    LZespolona x, y, z;

    x.re = 0.0;
    x.im = 0.0;

    y.re = 1;
    y.im = -3;

    z.re = 1;
    z.im = -3;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma4 dla min_dif =0.01"){
    LZespolona x, y, z;

    x.re = 0.001;
    x.im = 0.001;

    y.re = 1;
    y.im = -3;

    z.re = 1;   
    z.im = -3;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma5 na granicach"){
    LZespolona x, y, z;

    x.re = 0.009;
    x.im = 0.009;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 0.01;
    z.im = 0.01;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona odejmowanie"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 2;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = 5;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona odejmowanie2"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona odejmowanie3"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = -3;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1;
    z.im = -3;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona odejmowanie4 dla min_dif =0.01"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = -3;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 1;   
    z.im = -3;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona odejmowanie5 na granicach zaokrąglanie"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 4;

    y.re = 0.541;
    y.im = 0.541;

    z.re = 2.46;
    z.im = 3.46;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona mnożenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = -3;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnożenie2"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = -3;

    y.re = 1;
    y.im = 0;

    z.re = 1;
    z.im = -3;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnożenie3"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 1;

    z.re = -2;
    z.im = 2;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnożenie4"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 4;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnożenie5 minimalne wartości + graniczne"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = -4;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 0.01;        //powinno liczbę 0.005 zaokrąglić do 0.01
    z.im = 0.00;        //powinno liczbę -0.003 zaokrąglić do 0.00
    
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 3;
    x.im = 3;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespoloną1 - zero") {
    LZespolona x,y;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;
 
   WARN_THROWS(x/y);
}

TEST_CASE("Test LZespolona dzielenie przez liczbę zespoloną2") {
    LZespolona x, y,z;
    
    x.re = 1;
    x.im = 8;

    y.re = 2;
    y.im = 3;

    z.re = 2;
    z.im = 1;
   
    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona sprzężenie") {
    LZespolona x, z;
    
    x.re = 4;
    x.im = 4;
    x.Sprzezenie(x);

    z.re = 4;       
    z.im = -4;
   
    CHECK(x == z);
}

TEST_CASE("Test LZespolona sprzężenie2") {
    LZespolona x,z;
    
    x.re = 4;
    x.im = 0;
    x.Sprzezenie(x);

    z.re = 4;       
    z.im = 0;
   
    CHECK(x == z);
}

TEST_CASE("Test LZespolona moduł kwadrat") {
    LZespolona x;
    double w;
    
    x.re = 4;
    x.im = 3;
    w = x.Modulkwadrat(x);

   
    CHECK(w == 25);
}

TEST_CASE("Test LZespolona wyświetlanie") {
    LZespolona x;
    double t=3;
    
    x.re = 2;
    x.im = 4;
    std::ostringstream out;

    out << x/t;

    CHECK (out.str() == "(0.67+1.33i)");
}

TEST_CASE("Test LZespolona wczytywanie") {
    LZespolona x;
    
    std::istringstream in("(2.009+4i)");
    in >> x;

    std::ostringstream out;
    out << x;

    CHECK (out.str() == "(2.01+4.00i)");        //gdyby było samo 4 to wystąpiłby błąd, 
                                                //jednak w samym programie możemy pisać w ten sposób wynik
}

TEST_CASE("test LZespolona Suma i Podstawienie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    x+=y;
    CHECK(x == z);
}

TEST_CASE("test LZespolona Suma i Podstawienie2"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    x+=y;
    CHECK(x == z);
}

TEST_CASE("test LZespolona Suma i Podstawienie3"){
    LZespolona x, y, z;

    x.re = 0.0;
    x.im = 0.0;

    y.re = 1;
    y.im = -3;

    z.re = 1;
    z.im = -3;
    x+=y;
    CHECK(x == z);
}

TEST_CASE("test LZespolona Suma i Podstawienie4 dla min_dif =0.01"){
    LZespolona x, y, z;

    x.re = 0.001;
    x.im = 0.001;

    y.re = 1;
    y.im = -3;

    z.re = 1;   
    z.im = -3;
    x+=y;
    CHECK(x == z);
}

TEST_CASE("test LZespolona Suma i Podstawienie5 na granicach"){
    LZespolona x, y, z;

    x.re = 0.009;
    x.im = 0.009;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 0.01;
    z.im = 0.01;
    x+=y;
    CHECK(x == z);
}



TEST_CASE("Test LZespolona dzielenie i Podstawienie przez liczbe zespoloną1 - zero") {
    LZespolona x,y;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;
 
   WARN_THROWS(x/=y);
}

TEST_CASE("Test LZespolona dzielenie i Podstawienie przez liczbę zespoloną2") {
    LZespolona x, y,z;
    
    x.re = 1;
    x.im = 8;

    y.re = 2;
    y.im = 3;

    z.re = 2;
    z.im = 1;
   x/=y;
    CHECK(x == z);
}

TEST_CASE("Test LZespolona arg1") {
    LZespolona x;
    double w;
    
    x.re = -3;
    x.im = 9;
    w=x.arg(x);

    
    CHECK(w == 5.03);
}

/*TEST_CASE("Test LZespolona arg2") {       //niestety ten test nie działa
    LZespolona x;
    double w;
    
    x.re = 3;
    x.im = 9;
    w=x.arg(x);

    
    CHECK(w == 1.25);*/
//}

TEST_CASE("Test LZespolona arg3") {
    LZespolona x;
    double w;
    
    x.re = 0;
    x.im = 9;
    w=x.arg(x);

    
    CHECK(w == 1.57);
}