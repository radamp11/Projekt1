#include "liczby.h"

void powitanie(){
    cout<<"############################################"<<endl
        <<"**********KALKULATOR LICZB ULL INT**********"<<endl
        <<"############################################"<<endl<<endl
        <<"Wpisz slowo \"instrukcja\" w celu uzyskania pomocy,\nlub po prostu zacznij korzystac!"<<endl;
        }

void instrukcja (){
    cout<<endl<<"Pamietaj, ze zadna z wpisywanych przez Ciebie cyfr nie powinna przekraczac "<<ULL_MAX<<". "<<endl
        <<"Kazda instrukcje zatwierdzaj przyciskiem ENTER.\n"<<endl
        <<"Masz do dyspozycji dwie liczby: \"a\" oraz \"b\". Oto lista operacji, ktore mozesz wykonac: \n"
        <<"     zmien a - mozesz nadac liczbie a nowa wartosc\n"
        <<"     zmien b - mozesz nadac liczbie b nowa wartosc\n"
        <<"     a * b - wynikiem bedzie iloczyn tych dwoch liczb\n"
        <<"     a + b - suma\n"
        <<"     a - b - roznica\n"
        <<"     a = b? - porownanie. Wynikiem jest \"Tak\", jesli sa rowne; \"Nie\" w przeciwnym wypadku\n"
        <<"     a > b? oraz a < b? - analogicznie j.w.\n"
        <<"     a = b lub b = a - przypisuje liczbie po lewej watrosc tej po prawej\n"
        <<"     pokaz a - wyswietla liczbe a\n"
        <<"     pokaz b - analogicznie\n"
        <<"     koniec - konczy dzialanie programu."<<endl;
    cout<<"Liczby mozesz wprowadzac w trzech postaciach:\n"
        <<"     - znak znajduje sie na poczatku (lub go nie ma w przypadku liczby dodatniej), a kolejne cyfry oddzielone sa znakiem \"|\", np: -123|345|53535|2|0\n"
        <<"     - wpisujac znak na poczatku (lub nie, patrz wyzej) a nastepne cyfry podawac po spacji, np: - 1444 15325 89234 12\n"
        <<"     - w przypadku liczby jednocyfrowej, wpisz znak i po prostu podaj dana liczbe.\n"<<endl;
}

void dodawanie ( const Liczby & jeden, const Liczby & dwa ){
    cout<<jeden<<" + "<<dwa<<" = "<<(jeden + dwa)<<endl;
}

void odejmowanie ( const Liczby & jeden, const Liczby & dwa ){
    cout<<jeden<<" - "<<dwa<<" = "<<(jeden - dwa)<<endl;
}

void mnozenie ( const Liczby & jeden, const Liczby & dwa ){
    cout<<jeden<<" * "<<dwa<<" = "<<(jeden * dwa)<<endl;
}

void porownanie ( const Liczby & jeden, const Liczby & dwa ){
    if ( jeden == dwa ) cout<<"Tak"<<endl;
    else cout<<"Nie"<<endl;
}

void wiekszy ( const Liczby & jeden, const Liczby & dwa ){
    if ( jeden > dwa ) cout<<"Tak"<<endl;
    else cout<<"Nie"<<endl;
}

void mniejszy ( const Liczby & jeden, const Liczby & dwa ){
    if ( jeden < dwa ) cout<<"Tak"<<endl;
    else cout<<"Nie"<<endl;
}

void przypisz ( Liczby & jeden, string & str ){
    Liczby druga;
    int dlugosc = str.size();
    int i = 0;
    int wariant = -1111;    //0 - konstruktor string; 1 - konstruktor dla tablic; 2 - konstruktor dla liczby
    while ( i < dlugosc ){
        if ( str[i] == '|' && i >= 2) {
            wariant = 0;
            break;
        }
        else if ( str[i] == ' ' && i >= 2 ){
            wariant = 1;
            break;
        }
        else wariant = 2;
        ++i;
    }
    if ( wariant == 0 ){
        Liczby tymcz(str);
        druga = tymcz;
    }
    else if ( wariant == 1 ){
        int j = 0;
        bool znaczek = false;
        ull tabTymcz[MAX];
        if ( str[0] == '-' ){
            znaczek = true;
            str.erase( 0, 2 );
        }

        string::size_type wsk = 0;
        while ( !str.empty() ) {
            tabTymcz[j] = stoull ( str, &wsk, 0 );
            str = str.substr(wsk);
            ++j;
        }
        Liczby tymcz ( tabTymcz, j, znaczek );
        druga = tymcz;
    }
    else if ( wariant == 2 ){
        bool znaczek = false;
        if ( str[0] == '-' ){
            znaczek = true;
            str.erase( 0, 2 );
        }
        ull liczba = stoull ( str, nullptr, 0 );
        Liczby tymcz( liczba, znaczek );
        druga = tymcz;
    }
    else cout<<"Blad funkcji przypisz w przeszukiwaniu lancucha\n";
    jeden = druga;
}
