#include "liczby.h"

static void drukujTab ( ull tab[], int rozm ){
    for ( int i = 0; i < rozm; ++i ) cout<<tab[i]<<",";
}

void testKonstruktorow(){
    cout<<"**********************"<<endl;
    cout<<"**TEST KONSTRUKTOROW**"<<endl;
    cout<<"**********************"<<endl;
    string str1 = "-1244|23|18|156";
    string str2 = "12421241|55255|2535235|46|4111|4|4|5|6|235325|0";
    string str3 = "-321|235|25|023|22";
    ull jeden = 124242141241;
    ull dwa = -14412245;
    ull trzy = 555552532662;
    ull tab1[] = {124214, 2535, 6436, 666, 3111325, 5355 ,55, 0};
    int rozm1 = sizeof(tab1)/sizeof(ull);
    ull tab2[] = {12, 1444, 4623, 25555, 623, 1924, 412218, 412, 14, 12445, 11514214};
    int rozm2 = sizeof(tab2)/sizeof(ull);
    ull tab3[] = {234, 4124, 3534, 4576, 8568, 3346, 7568, 68468363, 86584, 99999, 4352};
    int rozm3 = sizeof(tab3)/sizeof(ull);
    Liczby testStr1(str1);
    Liczby testStr2(str2);
    Liczby testStr3(str3);
    Liczby testJeden(jeden, false);
    Liczby testDwa(dwa, true );
    Liczby testTrzy(trzy, false);
    Liczby testTab1(tab1, rozm1, true );
    Liczby testTab2(tab2, rozm2, true );
    Liczby testTab3(tab3, rozm3, false );
    Liczby domyslny;
    cout<<"Konstruktory string:"<<endl;

    cout<<"pierwszy; powinno być "<<str1<<" i jest"<<endl;
    testStr1.drukuj();
    cout<<"a tak wczytano: "<<endl;
    testStr1.drukujWspak();
    cout<<endl;

    cout<<"drugi; powinno być "<<str2<<" i jest"<<endl;
    testStr2.drukuj();
    cout<<"a tak wczytano: "<<endl;
    testStr2.drukujWspak();
    cout<<endl;

    cout<<"trzeci; powinno być "<<str3<<" i jest"<<endl;
    testStr3.drukuj();
    cout<<"a tak wczytano: "<<endl;
    testStr3.drukujWspak();

    cout<<endl<<"konstruktory liczb:"<<endl;

    cout<<"pierwszy; powinno być: "<<jeden<<"i jest: "<<endl;
    testJeden.drukuj();
    cout<<"a tak wczytano:\n";
    testJeden.drukujWspak();

    cout<<"drugi; powinno być: "<<dwa<<"i jest: "<<endl;
    testDwa.drukuj();
    cout<<"a tak wczytano:\n";
    testDwa.drukujWspak();

    cout<<"trzeci; powinno być: "<<trzy<<"i jest: "<<endl;
    testTrzy.drukuj();
    cout<<"a tak wczytano:\n";
    testTrzy.drukujWspak();

    cout<<endl<<"konstruktory tablic: "<<endl;

    cout<<"pierwszy; powinno byc:\n";
    drukujTab( tab1, rozm1 );
    cout<<"a jest: \n";
    testTab1.drukuj();
    cout<<"a wczytalo tak: \n";
    testTab1.drukujWspak();
    cout<<endl;

    cout<<"drugi; powinno byc:\n";
    drukujTab( tab2, rozm2 );
    cout<<"a jest: \n";
    testTab2.drukuj();
    cout<<"a wczytalo tak: \n";
    testTab2.drukujWspak();
    cout<<endl;

    cout<<"trzeci; powinno byc:\n";
    drukujTab( tab3, rozm3 );
    cout<<"a jest: \n";
    testTab3.drukuj();
    cout<<"a wczytalo tak: \n";
    testTab3.drukujWspak();
    cout<<endl;

    cout<<"dzialanie konstruktora domyslnego: \n";
    domyslny.drukuj();
    cout<<endl<<"KONIEC DZIALANIA TESTU KONSTRUKTOROW"<<endl;
}

void testOperatorow(){
    cout<<endl<<"TEST OPERATOROW"<<endl;
    string str1 = "-1244|23|18|156";
    string str2 = "12421241|55255|2535235|46|4111|4|4|5|6|235325|0";
    string str4 = "12421249|55255|2535235|46|4111|4|4|5|5|235325|0";
    string str3 = "-321|235|25|023|22";
    ull tab1[] = {124214, 2535, 6436, 666, 3111325, 5355 ,55, 0};
    int rozm1 = sizeof(tab1)/sizeof(ull);
    ull tab2[] = {12, 1444, 4623, 25555, 623, 1924, 412218, 412, 14, 12445, 11514214};
    int rozm2 = sizeof(tab2)/sizeof(ull);
    ull tab3[] = {234, 4124, 3534, 4576, 8568, 3346, 7568, 68468363, 86584, 99999, 4352};
    int rozm3 = sizeof(tab3)/sizeof(ull);
    Liczby porownanie1(str1);
    Liczby porownanie2(str1);
    Liczby porownanie3(str3);
    Liczby porownanie4(tab1, rozm1, true );
    Liczby porownanie5(tab2, rozm2, false );
    Liczby porownanie6(tab3, rozm3, false );
    Liczby porownanie7(str4);
    Liczby porownanie8(str2);
    cout<<"czy\n"; porownanie7.drukuj(); cout<<" > \n"; porownanie8.drukuj();
    cout<<"powinno być 1, a jest:\n"<<( porownanie7 > porownanie8 );

    cout<<"czy\n"; porownanie1.drukuj(); cout<<" == \n"; porownanie2.drukuj();
    cout<<endl<<"powinno byc 1, a jest:\n"<<( porownanie1 == porownanie2 );

    cout<<"czy\n"; porownanie1.drukuj(); cout<<" == \n"; porownanie3.drukuj();
    cout<<endl<<"powinno byc 0, a jest:\n"<<( porownanie1 == porownanie3 );

    cout<<endl<<"czy\n"; porownanie3.drukuj(); cout<<" > \n"; porownanie4.drukuj();
    cout<<"powinno byc 0, a jest:\n"<<( porownanie3 > porownanie4 );
    cout<<endl<<"a dla < powinno byc 1 i jest: "<<( porownanie3 < porownanie4 )<<endl;

    cout<<endl<<"operator przypisania\n";
    cout<<"przypisuje tej liczbie: \n";
    porownanie6.drukuj();
    cout<<"ta liczbe: \n";
    porownanie1.drukuj();
    porownanie6 = porownanie1;
    cout<<"i wyszlo: \n";
    porownanie6.drukuj();
}

void testOperArytm (){
    cout<<endl<<"TEST OPERATOROW ARYTMETYCZNYCH"<<endl;
    string str1 = "-200|100|500|1000";    //odjąć ujemną
    string str11 = "-300|101|101|501|1100";
    string str2 = "1200|55|25|46|411|4|4|5|6|235|0";    //odjąć dwie dodoatnie; mniejsza - większa; przeniesienie na prawie wszystkich pozycjach
    string str22 = "1209|55|25|46|411|4|4|5|5|235|0";
    string str3 = "82|123|100|200|300|400";     //dodać dwie dodatnie różnych długości
    string str33 = "124|436|11|98|345|100|233|1098";
    string str4 = "-18446744073709551600|200|300|400|500";      //dodać dwie ujemne z przeniesieniem przy najbardziej znaczącym bicie
    string str44 = "-9999999999999999991|144|289|520|420";
    string str5 = "1|2|3";
    string str55 = "2|3|4";

    ull tab1[] = {325, 34, 282, 300, 400};
    int len1 = sizeof(tab1)/sizeof(ull);
    ull tab2[] = {325, 14, 82, 150, 375};
    int len2 = sizeof(tab2)/sizeof(ull);

    ull jeden = 100;
    ull dwa = ULL_MAX - 90;

    Liczby porjeden( jeden , false );
    Liczby pordwa ( dwa , false );
    Liczby wyn6 = porjeden + pordwa;

    Liczby por1(str1);
    Liczby por11(str11); Liczby wyn1 = por1 - por11;
    Liczby por2(str2);
    Liczby por22(str22); Liczby wyn2 = por2 - por22;
    Liczby por3(str3);
    Liczby por33(str33); Liczby wyn3 = por3 + por33;
    Liczby por4(str4);
    Liczby por44(str44); Liczby wyn4 = por4 + por44;
    Liczby por5(str5);
    Liczby por55(str55); Liczby wyn5 = por5 + por55;
    Liczby wyn7 = por5 - por55;
    Liczby wyn8 = por55 - por5;

    Liczby porTab1(tab1, len1, false );
    Liczby porTab2(tab2, len2, false ); //wynik 9

    cout<<"Wynik 1:"<<endl<<wyn1<<"  wartosc max:  "<<ULL_MAX<<endl;    //przy okazji test operatora <<
    cout<<"Wynik 2:"<<endl; wyn2.drukuj(); cout<<endl;
    cout<<"Wynik 3:"<<endl; wyn3.drukuj(); cout<<endl;
    cout<<"Wynik 4:"<<endl; wyn4.drukuj(); cout<<endl;
    cout<<"Wynik 5:"<<endl; wyn5.drukuj(); cout<<endl;
    cout<<"Wynik 6:"<<endl; wyn6.drukuj(); cout<<endl;
    cout<<"Wynik 7:"<<endl; wyn7.drukuj(); cout<<endl;
    cout<<"Wynik 8:"<<endl; wyn8.drukuj(); cout<<endl;
    cout<<"Wynik 9:"<<endl<<(porTab1 - porTab2)<<endl;  //test na usuwanie zera wiodącego
    cout<<"Wynik 10:"<<endl<<(porTab2 - porTab1)<<endl;
    cout<<"Wynik 11: mnozenie"<<endl<<(por5 * por55)<<endl;
    const int przesuniecie = 3;
    cout<<"liczba"<<por5<<" bez przesuniecia bitowego"<<endl<<"a to ta sama liczba z przesunieciem o "<<przesuniecie<<"bitow:  ";
    por5 < przesuniecie;
    cout<<por5<<endl;
    cout<<"mnozenie: "<<por1<<" * "<<por11<<" = "<<endl<<(por1 * por11)<<endl;
    cout<<"mnozenie2: "<<por2<<" * "<<por22<<" = "<<endl<<(por2 * por22)<<endl;
    cout<<"mnozenie3: "<<por3<<" * "<<por33<<" = "<<endl<<(por3 * por33)<<endl;
}
