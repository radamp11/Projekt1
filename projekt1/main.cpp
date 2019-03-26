#include "liczby.h"
#include "testy.h"
#include "powloka.h"
using namespace std;

int main(){
    //testKonstruktorow();
    //testOperatorow();
    //testOperArytm();
    powitanie();
    string odpowiedz;
    string liczba;
    Liczby a;
    Liczby b;

    do {
        getline( cin, odpowiedz );

        if ( odpowiedz == "instrukcja" ) instrukcja();
        else if ( odpowiedz == "zmien a" ){
            cout<<"Nowa wartosc a = ";
            getline( cin, liczba );
            przypisz( a, liczba );
            liczba.clear();
        }
        else if ( odpowiedz == "zmien b" ){
            cout<<"Nowa wartosc b = ";
            getline( cin, liczba );
            przypisz( b, liczba );
            liczba.clear();
        }
        else if ( odpowiedz == "a * b" || odpowiedz == "b * a" ) mnozenie( a, b );
        else if ( odpowiedz == "a + b" || odpowiedz == "b + a" ) dodawanie( a, b );
        else if ( odpowiedz == "a - b" ) odejmowanie( a, b );
        else if ( odpowiedz == "b - a" ) odejmowanie( b, a );
        else if ( odpowiedz == "a = b?" || odpowiedz == "b = a?" ) porownanie( a, b );
        else if ( odpowiedz == "a > b?" ) wiekszy( a, b );
        else if ( odpowiedz == "a < b?" ) mniejszy( a, b );
        else if ( odpowiedz == "b > a?" ) wiekszy( b, a );
        else if ( odpowiedz == "b < a?" ) mniejszy( b, a );
        else if ( odpowiedz == "a = b" ) a = b;
        else if ( odpowiedz == "b = a" ) b = a;
        else if ( odpowiedz == "pokaz a" ) a.drukuj();
        else if ( odpowiedz == "pokaz b" ) b.drukuj();
        else if ( odpowiedz != "koniec") cout<<"Nie znam twojej komendy. Skorzystaj z komendy \"instrukcja\"."<<endl;
        if ( odpowiedz != "koniec" ) odpowiedz.clear();
    }
    while ( odpowiedz != "koniec" );

    cout<<endl<<"*****DO WIDZENIA!*****"<<endl;
    return 0;
}
