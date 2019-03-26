#ifndef LICZBY_H
#define LICZBY_H

#include <iostream>
#include <string>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
const ull ULL_MAX = ~( ull )0;
const int MAX = 100;

class Liczby{

    private:
        static const int ILOSC_MAX = 100;
        ull tabCyfr[ILOSC_MAX] = {0};
        int N;
        bool znak;  //false - dodatnia; true - ujemna

    public:
        Liczby();
        Liczby( ull tab [] , int dlugosc, bool zn );   //konstruktor dla tablicy cyfr
        Liczby( const string& licz );   //konstruktor dla napisu
        Liczby( ull li , bool zn );   //konstruktor dla pojedyńczej liczby

        void drukuj() const;
        void drukujWspak() const;
        int porownajModul( const Liczby &pierwsza, const Liczby &druga ) const;

        friend ostream & operator<<( ostream &os, const Liczby &L );
        bool operator==( const Liczby &L ) const;
        bool operator>( const Liczby &L ) const;
        bool operator<( const Liczby &L ) const;
        Liczby operator+( const Liczby &L ) const;
        Liczby operator-( const Liczby &L ) const;
        Liczby& operator=( const Liczby &L );
        Liczby& operator<( const int przes );   //przesunięcie bitowe w prawo o przes bitów
        Liczby operator*( const Liczby &L ) const;

        virtual ~Liczby();
};

#endif // LICZBY_H
