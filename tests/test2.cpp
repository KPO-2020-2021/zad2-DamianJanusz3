#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "Statystyki.hh"
#include "WyrazenieZesp.hh"


TEST_CASE("Test Statystyki wyliczanie % dobrych odpowiedzi") {
    staty x;
    double w;

    x.d = 64;
    x.z = 36;
    w = x.Podsumowanie(x);      //niestety wyświetla się w terminalu :(

    CHECK (w ==64);
}



TEST_CASE("Test WyrazenieZesp wyświetlanie i wczytywanie"){     //ten test nie działa za dobrze ale wyświetlanie i wczytywanie w samym programie działa dobrze
    WyrazenieZesp x;
    std::istringstream in("(0.6+2i)+(0.5+2i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(0.60+2.00i) + (0.50+2.00i)");
}

TEST_CASE("Test WyrazenieZesp obliczanie wartości dodawanie") {
    WyrazenieZesp x;
    LZespolona y;
    
    x.Arg1.re = 2;
    x.Arg1.im = 3;
    x.Arg2.re = 4;
    x.Arg2.im = -9;
    x.Op = Op_Dodaj;

    y= x.Oblicz(x);
    

    CHECK (y.re == 6);
    CHECK(y.im == -6);
}

TEST_CASE("Test WyrazenieZesp obliczanie wartości odejmowanie") {
    WyrazenieZesp x;
    LZespolona y;
    
    x.Arg1.re = 2;
    x.Arg1.im = 3;
    x.Arg2.re = 4;
    x.Arg2.im = -9;
    x.Op = Op_Odejmij;

    y= x.Oblicz(x);
    

    CHECK (y.re == -2);
    CHECK(y.im == 12);
}

TEST_CASE("Test WyrazenieZesp obliczanie wartości mnożenie") {
    WyrazenieZesp x;
    LZespolona y;
    
    x.Arg1.re = 2;
    x.Arg1.im = 3;
    x.Arg2.re = 4;
    x.Arg2.im = -9;
    x.Op = Op_Mnoz;

    y= x.Oblicz(x);
    

    CHECK (y.re == 35);
    CHECK(y.im == -6);
}

TEST_CASE("Test WyrazenieZesp obliczanie wartości dzielenie") {
    WyrazenieZesp x;
    LZespolona y;
    
    x.Arg1.re = 2;
    x.Arg1.im = 8;
    x.Arg2.re = 4;
    x.Arg2.im = 2;
    x.Op = Op_Dziel;

    y= x.Oblicz(x);
    

    CHECK (y.re == 1.2);
    CHECK(y.im == 1.4);
}

