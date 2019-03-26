#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include "liczby.h"
using namespace std;

//konstruktory i destruktor
/*
WAŻNE!
  konstruktory wczytują liczby od końca, co ma na celu ułatwić operacje arytmetyczne na nich
  w dodatku oznacza to, że indeks tablicy jest wagą danej pozycji
  metoda drukuj wypisuje je w takiej postaci, jak powinny wyglądać zapisane "normalnie"
*/

Liczby::Liczby(){
    znak = false;
    tabCyfr[0] = 0;
    N = 1;
}

Liczby::Liczby( ull tab [] , int dlugosc, bool zn ){
    znak = zn;
    if( dlugosc > ILOSC_MAX ){
        cout<<"Przekrczono dozwolona dlugosc liczby.\nWczytano pierwsze "<<ILOSC_MAX<<" cyfr."<<endl;
        dlugosc = ILOSC_MAX;
    }
    N = dlugosc;

    for( int i = 0; i < dlugosc; ++i ){
        tabCyfr[i] = tab[dlugosc - i - 1];
    }
}

Liczby::Liczby( const string& licz ){
    ull tabTymczasowa[ILOSC_MAX];
    int dlLancucha = licz.size();
    int idLiczby = 0;
    int i = 0;

    if( licz[i] == '-' ){
        znak = true;
        ++i;
    }
    else znak = false;

    string tymczasowy;
    while( i <= dlLancucha ){
        if( licz[i] == '|' || i == dlLancucha ){
            tabTymczasowa[idLiczby] = stoull( tymczasowy, nullptr, 0);
            ++idLiczby;
            tymczasowy.clear();
            ++i;
        }
        else{
            tymczasowy += licz[i];
            ++i;
        }
        if( idLiczby >= ILOSC_MAX - 1 ){
            cout<<"Przekrczono dozwolona dlugosc liczby.\nWczytano pierwsze "<<ILOSC_MAX<<" cyfr."<<endl;
            break;
        }
    }
    N = idLiczby ;
    for ( int i = 0; i < N; i++ ){
        tabCyfr[i] = tabTymczasowa[N - i - 1];
    }
}

Liczby::Liczby( ull li , bool zn ){
    znak = zn;
    N = 1;
    tabCyfr[0]=li;
}

Liczby::~Liczby() {}

void Liczby::drukuj() const {
    cout<<"Dlugosc liczby: "<<N<<endl<<"Liczba: ";
    if( znak == true ) cout<<"-";
    for(int i = N - 1; i >= 0; --i ){
        cout<<tabCyfr[i];
        if( i != 0 ) cout<<"|";
    }
    cout<<endl;
}

void Liczby::drukujWspak() const {
    cout<<"Dlugosc liczby: "<<N<<endl<<"Liczba: ";
    if( znak == true ) cout<<"-";
    for(int i = 0; i <= N - 1; ++i ){
        cout<<tabCyfr[i];
        if( i != N - 1 ) cout<<"|";
    }
    cout<<endl;
}
//zwraca -1, gdy pierwsza jest większa od drugiej, 0 gdy są równe, 1 gdy druga jest wieksza od pierwszej
//funkcja potrzebna do działania funkcji operatorów
int Liczby::porownajModul( const Liczby &pierwsza, const Liczby &druga ) const{
    int wynik = -123456;    //wartość błędu
    if ( pierwsza.N > druga.N ) wynik = -1;
    else if ( pierwsza.N < druga.N ) wynik = 1;
    else{   //gdy długoości są równe
        wynik = 0;
        for ( int i = pierwsza.N - 1; i >= 0; --i ){
            if ( pierwsza.tabCyfr[i] > druga.tabCyfr[i] ){
                wynik = -1;
                break;
            }
            else if ( pierwsza.tabCyfr[i] < druga.tabCyfr[i] ){
                wynik = 1;
                break;
            }
            else continue;
        }
    }
    return wynik;
}

//operatory

ostream& operator<<( ostream &os, const Liczby &L ){
    if( L.znak == true ) os<<"-";
    for ( int i = L.N - 1; i >= 0; --i ){
        os<<L.tabCyfr[i];
        if( i != 0 ) os<<"|";
    }
    return os;
}

bool Liczby::operator==( const Liczby &L ) const{
    bool wynik = false;
    if ( znak == L.znak && N == L.N ) wynik = true;
    for ( int i = 0; i < N; ++i ){
        if ( wynik == false ) break;
        else if ( tabCyfr[i] != L.tabCyfr[i] ) wynik = false;
        else continue;
    }
    return wynik;
}

bool Liczby::operator>( const Liczby &L ) const{
    if ( static_cast<int>(znak) < static_cast<int>(L.znak) ) return true;
    else if ( static_cast<int>(znak) > static_cast<int>(L.znak) ) return false;
    if( N > L.N && znak == false ) return true;
    else if ( N > L.N && znak == true ) return false;
    else if ( N < L.N && znak == false ) return false;
    else if ( N < L.N && znak == true ) return true;
    bool wynik = false;
    for ( int i = N - 1; i >= 0; --i ){
        if ( tabCyfr[i] > L.tabCyfr[i] && znak == false ){
            wynik = true;
            break;
        }
        else if ( tabCyfr[i] > L.tabCyfr[i] && znak == true ){
            wynik = false;
            break;
        }
        else if ( tabCyfr[i] < L.tabCyfr[i] && znak == false ){
            wynik = false;
            break;
        }
        else if ( tabCyfr[i] < L.tabCyfr[i] && znak == true ){
            wynik = true;
            break;
        }
    }
    return wynik;
}

bool Liczby::operator<( const Liczby &L ) const{
    if ( static_cast<int>(znak) > static_cast<int>(L.znak) ) return true;
    else if ( static_cast<int>(znak) < static_cast<int>(L.znak) ) return false;
    if( N < L.N && znak == false ) return true;     //nie sprawdzam obydwu znaków, bo jak program tu doszedł to na pewno są takie same
    else if ( N < L.N && znak == true ) return false;
    else if ( N > L.N && znak == false ) return false;
    else if ( N > L.N && znak == true ) return true;
    bool wynik = false;
    for ( int i = N - 1; i >= 0; --i ){
        if ( tabCyfr[i] < L.tabCyfr[i] && znak == false ){
            wynik = true;
            break;
        }
        else if ( tabCyfr[i] < L.tabCyfr[i] && znak == true ){
            wynik = false;
            break;
        }
        else if ( tabCyfr[i] > L.tabCyfr[i] && znak == false ){
            wynik = false;
            break;
        }
        else if ( tabCyfr[i] > L.tabCyfr[i] && znak == true ){
            wynik = true;
            break;
        }
    }
    return wynik;
}

Liczby& Liczby::operator=( const Liczby &L ){
    tabCyfr[ILOSC_MAX]={0};
    znak = L.znak;
    N = L.N;
    for ( int i = 0; i < N; ++i ){
        tabCyfr[i] = L.tabCyfr[i];
    }
    return *this;
}

Liczby Liczby::operator+( const Liczby &L ) const{
    Liczby suma;    //domyslnie rowna 0
    int stop = 0;
    ull przeniesienie = 0;

    if ( znak == L.znak ){
        if ( znak == false && L.znak == false ) suma.znak = false;
        else suma.znak = true;

        if ( N > L.N ) stop = N;
        else stop = L.N;
        suma.N = stop;
        for( int i = 0; i < stop; ++i ){
            suma.tabCyfr[i] = tabCyfr[i] + L.tabCyfr[i] + przeniesienie;
                //jeżeli suma wykroczy poza zakres ull, to będzie mniejsza od co najmniej jednego ze składników
                //w przeciwnym wypadku będzie większa od obu lub równa, gdy jeden ze składników to zero
            if ( (suma.tabCyfr[i] < tabCyfr[i]) || (suma.tabCyfr[i] < L.tabCyfr[i]) ) przeniesienie = 1;
            else przeniesienie = 0;

            if ( i == stop - 1 && przeniesienie == 1 && stop < ILOSC_MAX ) {
                suma.tabCyfr[i + 1]++;  //gdy wystąpi przeniesienie poza zakresem pętli
                suma.N ++;
            }
        }
    }
    else {  //składniki są równych znaków
        if ( porownajModul( *this, L ) == 0 ) return suma;

        if ( porownajModul( *this, L ) == -1 ){
            przeniesienie = 0;
            stop = N;
            for ( int i = 0; i < stop; ++i ){
                suma.tabCyfr[i] = tabCyfr[i] - L.tabCyfr[i] - przeniesienie;
                if ( tabCyfr[i] < L.tabCyfr[i] || (tabCyfr[i] == L.tabCyfr[i] && przeniesienie == 1) ) przeniesienie = 1;
                else przeniesienie = 0;
            }
            if ( znak == false && L.znak == true ) suma.znak = false;
            else suma.znak = true;
            suma.N = (suma.tabCyfr[stop - 1] == 0)? --stop : stop;  //pozbywanie się wiodącego zera
        }
        else if ( porownajModul( *this, L ) == 1 ){
            przeniesienie = 0;
            stop = L.N;
            for ( int i = 0; i < stop; ++i ){
                suma.tabCyfr[i] = L.tabCyfr[i] - tabCyfr[i] - przeniesienie;
                if ( L.tabCyfr[i] < tabCyfr[i] || (tabCyfr[i] == L.tabCyfr[i] && przeniesienie == 1) ) przeniesienie = 1;
                else przeniesienie = 0;
            }
            if ( znak == false && L.znak == true ) suma.znak = true;
            else suma.znak = false;
            suma.N = (suma.tabCyfr[stop - 1] == 0)? --stop : stop;
        }
    }
    return suma;
}

Liczby Liczby::operator-( const Liczby &L ) const{
    Liczby roznica;
    Liczby tymcz;

    if ( znak == false && L.znak == true ){
        tymcz = L;
        tymcz.znak = false;
        roznica = *this + tymcz;
    }
    else if ( znak == true && L.znak == false ){
        tymcz = L;
        tymcz.znak = true;
        roznica = *this + tymcz;
    }
    else if ( znak == false && L.znak == false ){
        tymcz = L;
        tymcz.znak = true;
        roznica = *this + tymcz;
    }
    else{
        tymcz = L;
        tymcz.znak = false;
        roznica = *this + tymcz;
    }
    return roznica;
}
//potrzebne do mnożenia
Liczby& Liczby::operator<( const int przes ){
    for ( int i = N - 1; i >= 0; --i ){
        tabCyfr[i + przes] = tabCyfr[i];
    }
    for ( int j = przes - 1; j >= 0; --j ){
        tabCyfr[j] = 0;
    }
    N += przes;
    return *this;
}

Liczby Liczby::operator*( const Liczby &L ) const{
    Liczby iloczyn;
    Liczby tymcz;

    if ( N + L.N > ILOSC_MAX ) cout<<"Iloczyn danych liczb moze przekraczac dozwolony zakres. Wynik moze byc bledny.\nZwieksz limit danych.\n";
    for( int i = 0; i < N; ++i ){
        for ( ull j = 0; j < L.tabCyfr[i] ; ++j ){
            tymcz = tymcz + *this;
        }
        tymcz < i;  //przesuwa każdy ze składników mnożenia o wagę danej pozycji jak w zwykłym mnożeniu pisemnym
        iloczyn = iloczyn + tymcz;
        for( int i = 0; i < tymcz.N; ++i ){
            tymcz.tabCyfr[i] = 0;
        }
        tymcz.N = 1;
        tymcz.znak = false;
    }
    if ( znak == L.znak ) iloczyn.znak = false;
    else iloczyn.znak = true;
    return iloczyn;
}
