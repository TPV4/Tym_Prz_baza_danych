#include <iostream>
#include <ios>
#include <limits>
#include <string>
#include <cstring>
#include <string.h>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

class Produkt
{
    public:
        char nazwa[256];
        string kategoria;
        int liczba;
        double cena;
        double waga;
        double cena_waga;
        char data[256];
        vector<string> dodatki;
};

class Ciastko : public Produkt
    {
        public:
            void kategoryzacja()
            {
                kategoria="ciastko";
            }
    };
class Bulka : public Produkt
    {
        public:
            void kategoryzacja()
            {
                kategoria="bulka";
            }
    };
class Chleb : public Produkt
    {
        public:
            void kategoryzacja()
            {
                kategoria="chleb";
            }
    };
class Drozdzowka : public Produkt
    {
        public:
            void kategoryzacja()
            {
                kategoria="drozdzowka";
            }
    };
class Tort : public Produkt
    {
        public:
            void kategoryzacja()
            {
                kategoria="tort";
            }
    };
class Paczek : public Produkt
    {
        public:
            void kategoryzacja()
            {
                kategoria="paczek";
            }
    };
void lista(vector<Produkt>& produkty)
{
    vector<string> num;
    string str;
    lista:
    int wielkosc, x=1;
    wielkosc=produkty.size();
    if (wielkosc==0)
    {
        cout<<"Brak produktow\n";
        goto kon;
    }
    else
    {
        for (int i=0; i<wielkosc;i++)
        {
            x++;
            cout<<i+1<<") ";
            for (int j=0;j<strlen(produkty[i].nazwa);j++)
            {
                cout<<produkty[i].nazwa[j];
            }
            cout<<" - "<<produkty[i].kategoria<<"\n";
            str=to_string(x);
            num.push_back(str);
        }
    }
    powrot:
    cout<<"\nWpisz numer produktu, aby zobaczyc jego dane.\nWpisz '0' by wrocic do menu\n";
    int pow;
    string pow_str;
    cin>>pow;
    for (int k=0; k<wielkosc; k++)
    {
        pow_str=to_string(pow);
        if (any_of(num.begin(), num.end(), pow_str))
        {
            if (pow==k+1)
            {
                for(int n=0; n<strlen(produkty[pow-1].nazwa); n++)
                {
                    cout<<produkty[pow-1].nazwa[n];
                }
                cout<<":\nkategoria - "<<produkty[pow-1].kategoria;
                cout<<"\nliczba - "<<produkty[pow-1].liczba;
                cout<<"\ncena - "<<produkty[pow-1].cena;
                cout<<"\nwaga - "<<produkty[pow-1].waga;
                cout<<"\ncena za kg - "<<produkty[pow-1].cena_waga;
                cout<<"\ndata dostawy - ";
                for (int p=0; p<strlen(produkty[pow-1].data);p++)
                {
                    cout<<produkty[pow-1].data[p];
                }
                cout<<"\ndodatki:";
                for (int t=0; t<produkty[pow-1].dodatki.size(); t++)
                {
                    cout<<"\n -"<<produkty[pow-1].dodatki[t];
                }
                cout<<"\nWpisz '1' by wrocic do listy produktow. Wpisz '2' by wrocic do menu glownego.\n";
                int wyb;
                cin>>wyb;
                if (wyb==1)
                {
                    goto lista;
                }
                else if (wyb==2)
                {
                    goto kon;
                }
                else
                {
                    cout<<"blad\n";
                    goto powrot;
                }
            }
            else if (pow==0)
            {
                goto kon;
            }
        }
        else
        {
            cout<<"blad\n";
            goto powrot;
        }
    }
    kon:
    num.clear();
}
void pomocnicza1 (Produkt P, vector<Produkt>& produkty)
{
    string nazw, licz, wag, cen, cenwag, dat, dot;
    cout<<"Podaj nazwe produktu\n";
    cin.ignore();
    getline(cin, nazw);
    int a;
    int wielkoscN=nazw.size();
    strcpy(P.nazwa, nazw.c_str());
    cout<<"Podaj liczbe produktow\n";
    cin>>licz;
    int liczb=stoi(licz);
    P.liczba=liczb;
    cout<<"Podaj wage produktu (dag)\n";
    cin>>wag;
    double wagg=stod(wag);
    P.waga=wagg;
    cout<<"Podaj cene za sztuke\n";
    cin>>cen;
    double cenn=stod(cen);
    P.cena=cenn;
    cout<<"Podaj cene za kg\n";
    cin>>cenwag;
    double cenwagg=stod(cenwag);
    P.cena_waga=cenwagg;
    cout<<"Podaj przewidywana date dostawy\n";
    cin.ignore();
    getline(cin, dat);
    int wielkoscD=dat.size();
    strcpy(P.data, dat.c_str());
    cout<<"Podaj dodatki wystepujace w produkcie.\n(Aby zakonczyc wprowadzanie wpisz 'brak')\n";
    petla1:
    getline(cin, dot);
    if (dot != "brak")
    {
        P.dodatki.push_back(dot);
        dot.clear();
        goto petla1;
    }
    produkty.push_back(P);
    
}
void dodajProdukt(vector<Produkt>& produkty)
{
    pytanie:
    {
        int typ;
        cout<<"Wybierz typ produktu:\n1) ciastko\n2) bulka\n3) chleb\n4) drozdzowka\n5) tort\n6) wroc do menu\n";
        cin>>typ;
        if (typ==1)
        {
                Ciastko prod;
                prod.kategoryzacja();
                pomocnicza1(prod, produkty);
                cout<<"Produkt dodany\n";
        }
        else if (typ==2)
        {
                Bulka prod;
                prod.kategoryzacja();
                pomocnicza1(prod, produkty);
                cout<<"Produkt dodany\n";
        }
        else if (typ==3)
        {
                Chleb prod;
                prod.kategoryzacja();
                pomocnicza1(prod, produkty);
                cout<<"Produkt dodany\n";
        }
        else if (typ==4)
        {
                Drozdzowka prod;
                prod.kategoryzacja();
                pomocnicza1(prod, produkty);
                cout<<"Produkt dodany\n";
        }
        else if (typ==5)
        {
                Tort prod;
                prod.kategoryzacja();
                pomocnicza1(prod, produkty);
                cout<<"Produkt dodany\n";
        }
        else if (typ==6)
        {}
        else
        {
            std::cout<<"blad\n";
            goto pytanie;
        }
    }
}
void pomocnicza2 (vector<Produkt>& produkty, int odpowiedz)
{
    vector<Produkt> temp;
    for (int i=0;i<odpowiedz-1;i++)
    {
        temp[i]=produkty[i];
    }
    int wielkosc=produkty.size();
    for (int j=odpowiedz;j<wielkosc;j++)
    {
        temp[j-1]=produkty[j];
    }
    produkty.clear();
    int wielkoscT=temp.size();
    for (int k=0;k<wielkoscT;k++)
    {
        produkty[k]=temp[k];
    }
    temp.clear();
}
void usunProdukt(vector<Produkt>& produkty)
{
    cout<<"Wybierz produkt, ktory chcesz usunac.\n";
    int wielkosc=produkty.size();
    for (int i=0; i<wielkosc; i++)
    {
        cout<<i+1<<") ";
        for (int j=0;j<strlen(produkty[i].nazwa);j++)
        {
            cout<<produkty[i].nazwa;
        }
        cout<<"\n";
    }
    int odp;
    cin>>odp;
    pomocnicza2 (produkty, odp);
}
void zmienDane(vector<Produkt>& produkty)
{
    poczatek:
    cout<<"Wybierz produkt, ktorego dane chcesz zmienic.\n";
    int wielkosc=produkty.size();
    int x=1;
    for (int j=0; j<wielkosc; j++)
    {
        int wielN=strlen(produkty[j].nazwa);
        cout<<j+1<<") ";
        for (int k=0;k<wielN;k++)
        {
            cout<<produkty[j].nazwa[k];
        }
        cout<<"\n";
        x++;
    }
    cout<<x<<") wroc do menu\n";
    int odp1, odp2;
    cin>>odp1;
    if (odp1==x)
    {
        goto koniec;
    }
    wybor1:
    cout<<"ktore dane chcesz zmienic\n";
    cout<<"1) nazwa: ";
    for (int i=0;i<strlen(produkty[odp1-1].nazwa);i++)
    {
        cout<<produkty[odp1-1].nazwa[i];
    }
    cout<<"\n";
    cout<<"2) liczba: "<<produkty[odp1-1].liczba<<"\n";
    cout<<"3) cena: "<<produkty[odp1-1].cena<<"\n";
    cout<<"4) waga (dag): "<<produkty[odp1-1].waga<<"\n";
    cout<<"5) cena za kg: "<<produkty[odp1-1].cena_waga<<"\n";
    cout<<"6) dodatki\n";
    cout<<"7) wroc\n";
    cin>>odp2;
    if (odp2==1)
    {
        cout<<"Wprowadz nowa nazwe\n";
        string nowa1;
        cin.ignore();
        getline(cin, nowa1);
        strcpy(produkty[odp1-1].nazwa, nowa1.c_str());
    }
    else if(odp2==2)
    {
        cout<<"Wprowadz nowa liczbe produktu\n";
        int nowa2;
        cin>>nowa2;
        produkty[odp1-1].liczba=nowa2;
    }
    else if(odp2==3)
    {
        cout<<"Wprowadz nowa cene\n";
        double nowa3;
        cin>>nowa3;
        produkty[odp1-1].cena=nowa3;
    }
    else if(odp2==4)
    {
        cout<<"Wprowadz nowa wage\n";
        double nowa4;
        cin>>nowa4;
        produkty[odp1-1].waga=nowa4;
    }
    else if(odp2==5)
    {
        cout<<"Wprowadz nowa cene wagowa\n";
        double nowa5;
        cin>>nowa5;
        produkty[odp1-1].cena_waga=nowa5;
    }
    else if(odp2==6)
    {
        cout<<"Obecne dodatki:\n";
        for (int j=0;j<produkty[odp1-1].dodatki.size();j++)
        {
            cout<<j+1<<") "<<produkty[odp1-1].dodatki[j]<<"\n";
        }
        cout<<"Wybierz dodatek aby go zamienic lub usunac, albo wpisz '0', aby dodac dodatek.\n";
        int odp3;
        cin>>odp3;
        if (odp3==0)
        {
            cout<<"Wpisz nowy dodatek\n";
            string nowa6;
            cin.ignore();
            getline(cin, nowa6);
            produkty[odp1-1].dodatki.push_back(nowa6);
        }
        else
        {
            cout<<"1) Zamien dodatek\n2) Usun dodatek\n";
            int odp4;
            cin>>odp4;
            if (odp4==1)
            {
                cout<<"Wprowadz nowy dodatek\n";
                string nowy;
                cin.ignore();
                getline(cin, nowy);
                produkty[odp1-1].dodatki[odp3-1].assign(nowy);
            }
            else if(odp4==2)
            {
                vector<string> temp;
                for (int k=0;k<odp3-1;k++)
                {
                    temp[k]=produkty[odp1-1].dodatki[k];
                }
                if (odp3<=produkty[odp1-1].dodatki.size())
                {
                    for (int l=odp3;l<produkty[odp1-1].dodatki.size();l++)
                    {
                        temp[l]=produkty[odp1-1].dodatki[l];
                    }
                }
                produkty[odp1-1].dodatki.clear();
                for (int i=0;i<temp.size();i++)
                {
                    produkty[odp1-1].dodatki[i]=temp[i];
                }
                temp.clear();
            }
            else
            {
                cout<<"blad\n";
                goto wybor1;
            }
        }
    }
    else if(odp2==7)
    {
        goto poczatek;
    }
    else
    {
        cout<<"blad\n";
        goto wybor1;
    }
    ostdec:
    cout<<"1) Konynuuj zmiane danych\n2) Powrot do menu\n";
    int ostateczna_decyzja;
    cin>>ostateczna_decyzja;
    switch (ostateczna_decyzja)
    {
        case 1:
            goto wybor1;
        case 2:
            break;
        default:
            cout<<"blad\n";
            goto ostdec;
    }
    koniec:;
}
void zmienDate(vector<Produkt>& produkty)
{
    poczatek:
    cout<<"Wybierz produkt, ktorego date dostawy chcesz zmienic.\n";
    for (int i=0; i<produkty.size(); i++)
    {
        cout<<i+1<<") ";
        int wielN=strlen(produkty[i].nazwa);
        for (int j=0;j<wielN;j++)
        {
            cout<<produkty[i].nazwa[j];
        }
        cout<<" - ";
        int wielD=strlen(produkty[i].data);
        for (int k=0;k<wielD;k++)
        {
            cout<<produkty[i].data[k];
        }
        cout<<"\n";
    }
    int odp1;
    cin>>odp1;
    cout<<"Wpisz nowa date dostawy\n";
    string nowa_data;
    cin.ignore();
    getline(cin, nowa_data);
    strcpy(produkty[odp1-1].data, nowa_data.c_str());
    cout<<"1) Wprowadz dalsze zmiany\n2) Powrot do menu\n";
    int odp2;
    cin>>odp2;
    if (odp2==1)
    {
        goto poczatek;
    }
}
void wyszukaj(vector<Produkt> produkty)
{
    poczatek:
    cout<<"1) Wyszukaj po nazwie\n2) Wyszukaj po kategorii\n";
    char odp1;
    int wielkosc=produkty.size();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(odp1);
    int licznik, x;
    if (odp1=='1')
    {
        cout<<"Wprowadz szukane haslo (min. 3 znaki)\n";
        string wprow;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, wprow);
        cout<<"Wyniki wyszukiwania:\n";
        for (int i=0;i<wielkosc;i++)
        {
            petla1:
            licznik=0;
            x=0;
            for (int j=0;j<strlen(produkty[i].nazwa);j++)
            {
                for (int k=x;k<wprow.length();k++)
                {
                    if (wprow[k]==produkty[i].nazwa[j])
                    {
                        licznik++;
                        x++;
                        if (licznik==3)
                        {
                            for (int n=0;n<strlen(produkty[i].nazwa);n++)
                            {
                                cout<<produkty[i].nazwa[n];
                            }
                            cout<<"\n";
                            i++;
                            goto petla1;
                        }
                        break;
                    }
                    else
                    {
                        licznik=0;
                        x=0;
                    }
                }
            }
        }

    }
    else if (odp1=='2')
    {
        cout<<"Wprowadz szukane haslo (min. 3 znaki)\n";
        string kat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, kat);
        cout<<"Wyniki wyszukiwania:\n";
        for (int i=0;i<wielkosc;i++)
        {
            petla2:
            licznik=0;
            x=0;
            int n=produkty[i].kategoria.length();
            for (int j=0; j<n; j++)
            {
                for (int k=x;k<kat.length();k++)
                {
                    if (kat[k]==produkty[i].kategoria[j])
                    {
                        licznik++;
                        x++;
                        if (licznik==3)
                        {
                            for (int t=0; t<strlen(produkty[i].nazwa); t++)
                            {
                                cout<<produkty[i].nazwa[t];
                            }
                            cout<<" - "<<produkty[i].kategoria<<"\n";
                            i++;
                            goto petla2;
                        }
                        break;
                    }
                    else
                    {
                        licznik=0;
                        x=0;
                    }
                }
            }
        }
    }
    else
    {
        cout<<"blad\n";
        goto poczatek;
    }
    cout<<"1) Kontynuuj wyszukiwanie\n2) Powrot do menu\n";
    int odp2;
    cin>>odp2;
    if (odp2==1)
    {
        goto poczatek;
    }
}
void zapisz(vector<Produkt>& produkty)
{
    string nazwa;
    cout<<"Podaj nazwe pliku\n";
    cin.ignore();
    getline(cin, nazwa);
    nazwa=nazwa+".txt";
    ofstream plik (nazwa);
    if (plik.is_open())
    {
        //dodanie nagłówka
        plik<<"nazwa, kategoria, liczba, cena, waga, cena za kg, data dostawy, dodatki\n";
        int wielkosc=produkty.size();
        for (int i=0; i<wielkosc;i++)
        {
            string naz = produkty[i].nazwa;
            string kat = produkty[i].kategoria;
            string licz = to_string(produkty[i].liczba);
            string cen = to_string(produkty[i].cena);
            string wag = to_string(produkty[i].waga);
            string cenwag = to_string(produkty[i].cena_waga);
            string dat = produkty[i].data;
            string dod = "{";
            for (int j=0; j<produkty[i].dodatki.size();j++)
            {
                dod=dod+produkty[i].dodatki[j];
                if (j<produkty[i].dodatki.size()-1)
                {
                    dod=dod+", ";
                }
            }
            dod=dod+"}";
            string wiersz = naz+" - "+kat+", "+licz+", "+cen+", "+wag+", "+cenwag+", "+dat+", "+dod+"\n";
            plik<<wiersz;
        }
    }
    plik.close();

}
void pomocnicza3(vector<Produkt>& produkty, char naz[256], int licz, double cen, double wag, double cenwag, char dat[256], vector<string> dodatki)
{
    for (int l=0; l<strlen(naz); l++)
    {
        produkty.back().nazwa[l]=naz[l];
    }
    produkty.back().liczba=licz;
    produkty.back().cena=cen;
    produkty.back().waga=wag;
    produkty.back().cena_waga=cenwag;
    for (int a=0; a<strlen(dat); a++)
        {
            produkty.back().data[a]=dat[a];
        }
    for (int b=0; b<dodatki.size(); b++)
        {
            produkty.back().dodatki.push_back(dodatki[b]);
        }
}
void wczytaj(vector<Produkt>& produkty)
{
    string nazwa_plik;
    cout<<"Podaj nazwe pliku, z ktorego chcesz wczytac dane (tylko pliki '.txt')\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nazwa_plik);
    nazwa_plik=nazwa_plik+".txt";
    ifstream plik(nazwa_plik);
    vector<string> wiersze;
    string wiersz;
    if (plik.good() && plik.is_open())
    {
        while(getline(plik, wiersz))
        {
            wiersze.push_back(wiersz);
        }
        wiersze.erase(wiersze.begin());
        string nazwa, kategoria, liczba, cena, waga, cenawaga, data, dodatek;
        vector<string> dodatki;
        int x;
        for (int i=0; i<wiersze.size(); i++)
        {
            x=0;
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!='-')
                {
                    nazwa=nazwa+wiersze[i][j];
                }
                else
                {
                    nazwa.erase(nazwa.end()-1, nazwa.end());
                    x+=2;
                    break;
                }
                x++;
            }
            char naz[256];
            strcpy(naz, nazwa.c_str());
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!=' ')
                {
                    kategoria=kategoria+wiersze[i][j];
                }
                else
                {
                    kategoria.erase(kategoria.end()-1, kategoria.end());
                    x++;
                    break;
                }
                x++;
            }
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!=' ')
                {
                    liczba=liczba+wiersze[i][j];
                }
                else
                {
                    liczba.erase(liczba.end()-1, liczba.end());
                    x++;
                    break;
                }
                x++;
            }
            int licz=stoi(liczba);
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!=' ')
                {
                    cena=cena+wiersze[i][j];
                }
                else
                {
                    cena.erase(cena.end()-1, cena.end());
                    x++;
                    break;
                }
                x++;
            }
            double cen=stod(cena);
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!=' ')
                {
                    waga=waga+wiersze[i][j];
                }
                else
                {
                    waga.erase(waga.end()-1, waga.end());
                    x++;
                    break;
                }
                x++;
            }
            double wag=stod(waga);
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!=' ')
                {
                    cenawaga=cenawaga+wiersze[i][j];
                }
                else
                {
                    cenawaga.erase(cenawaga.end()-1, cenawaga.end());
                    x++;
                    break;
                }
                x++;
            }
            double cenwag=stod(cenawaga);
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!=' ')
                {
                    data=data+wiersze[i][j];
                }
                else
                {
                    data.erase(data.end()-1, data.end());
                    x+=2;
                    break;
                }
                x++;
            }
            char dat[256];
            strcpy(dat, data.c_str());
            for (int j=x; j<wiersze[i].length(); j++)
            {
                if (wiersze[i][j]!='}')
                {
                    if (wiersze[i][j]!=',')
                    {
                        dodatek=dodatek+wiersze[i][j];
                    }
                    else
                    {
                        x++;
                        j++;
                        dodatki.push_back(dodatek);
                        dodatek.clear();
                    }
                }
                else
                {
                    dodatki.push_back(dodatek);
                    dodatek.clear();
                }
                x++;
            }
            if (kategoria=="chleb")
            {
                Chleb prod;
                prod.kategoryzacja();
                produkty.push_back(prod);
                pomocnicza3(produkty, naz, licz, cen, wag, cenwag, dat, dodatki);
            }
            else if (kategoria=="paczek")
            {
                Paczek prod;
                prod.kategoryzacja();
                produkty.push_back(prod);
                pomocnicza3(produkty, naz, licz, cen, wag, cenwag, dat, dodatki);
            }
            else if (kategoria=="ciastko")
            {
                Ciastko prod;
                prod.kategoryzacja();
                produkty.push_back(prod);
                pomocnicza3(produkty, naz, licz, cen, wag, cenwag, dat, dodatki);
            }
            else if (kategoria=="bulka")
            {
                Bulka prod;
                prod.kategoryzacja();
                produkty.push_back(prod);
                pomocnicza3(produkty, naz, licz, cen, wag, cenwag, dat, dodatki);
            }
            else if (kategoria=="tort")
            {
                Tort prod;
                prod.kategoryzacja();
                produkty.push_back(prod);
                pomocnicza3(produkty, naz, licz, cen, wag, cenwag, dat, dodatki);
            }
            else if (kategoria=="drozdzowka")
            {
                Drozdzowka prod;
                prod.kategoryzacja();
                produkty.push_back(prod);
                pomocnicza3(produkty, naz, licz, cen, wag, cenwag, dat, dodatki);
            }
            nazwa.clear();
            kategoria.clear();
            liczba.clear();
            cena.clear();
            waga.clear();
            cenawaga.clear();
            data.clear();
            dodatki.clear();
        }
    }
    else
    {
        cout<<"blad wczytywania\n";
    }
    plik.close();
    }
int main()
{
    vector<Produkt> produkty;
    MenuGlowne:
    int czynnosc;
    cout<<"1) Wyswietl wszystkie produkty\n2) Dodaj produkt \n3) Usun produkt \n4) Zmien dane produktu \n5) Zmien date dostawy \n6) Wyszukaj produkt \n7) Zapisz dane \n8) Wczytaj dane z pliku\n9) Zakoncz program\n";
    cout<<"Podaj czynnosc: \n";
    cin>>czynnosc;
    switch (czynnosc)
    {
        case 1:
            lista(produkty);
            goto MenuGlowne;
        case 2:
            dodajProdukt(produkty);
            goto MenuGlowne;
        case 3:
            usunProdukt(produkty);
            goto MenuGlowne;
        case 4:
            zmienDane(produkty);
            goto MenuGlowne;
        case 5:
            zmienDate(produkty);
            goto MenuGlowne;
        case 6:
            wyszukaj(produkty);
            goto MenuGlowne;
        case 7:
            zapisz(produkty);
            goto MenuGlowne;
        case 8:
            wczytaj(produkty);
            goto MenuGlowne;
        case 9:
            break;
        default:
            cout<<"Niepoprawna czynnosc.\n";
            goto MenuGlowne;
    }   
    return 0;
}

