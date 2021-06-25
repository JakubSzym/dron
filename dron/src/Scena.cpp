#include "Scena.hh"

/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p Scena
*/

using namespace std;
using namespace PzG;
#define MENU 'm'
#define RUCH 'r'
#define OBROT 'o'
#define KONIEC 'k'

void Scena::ustawPrzeszkody(){
  Kostka kostka;
  Pret kij;
  Powierzchnia sciana;

  kostka.ustawPoczWsp("kostkaLok.dat", "kostka.dat");
  kij.ustawPoczWsp("pretLok.dat", "pret.dat");
  sciana.ustawPoczWsp("scianaLok.dat", "sciana.dat");

  lacze.DodajNazwePliku("kostka.dat");
  lacze.DodajNazwePliku("pret.dat");
  lacze.DodajNazwePliku("sciana.dat");
  
  przeszkody.push_back(&kostka);
  przeszkody.push_back(&kij);
  przeszkody.push_back(&sciana);
}

void Scena::wyswietlMenu(){
  cout<<"r - zadaj ruch na wprost"<<endl;
    cout<<"o - zadaj zmiane orientacji"<<endl;
    cout<<"m - wyswietl menu"<<endl;
    cout<<"k - koniec dzialania programu"<<endl;
}

void Scena::przesunDrona(){
  int ile=1;
  double kat, odleglosc;
  bool wynurzenie, zderzenie;
    cout << "Podaj wartosc kata (wznoszenia/opadania) w stopniach"<<endl;
    cout << "Wartosc kata<";
    cin >> kat;
    if(cin.fail()) {
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "Nieznana wartosc" <<endl;
    }
    cout<< "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron"<<endl;
    cout<< "Wartosc odleglosci<";   
    cin >> odleglosc;
    if(cin.fail()){
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "Nieznana wartosc" << endl;
    }

    
    for(int licz=0; licz<odleglosc && ile != odleglosc; licz++){
      ile++;
      wynurzenie = dron.wezKadlub().napotkano_wode();
      zderzenie = dron.wezKadlub().napotkano_dno();
      
      if(zderzenie){ break; }
      
      if(wynurzenie){
	if(kat <= 90){
	  if(!dron.przesun(kat--, licz--)){ cerr<<"Nie udalo sie wykonac translacji drona"<<endl;}
	  if(!woda.translacja(kat, licz)){cerr<<"Blad translacji wody"<<endl;}
	  if(!dno.translacja(kat, licz)){ cerr << "Blad translacji dna" << endl; }


	} else {
	  if(!dron.przesun(kat++, licz--)){ cerr<<"Nie udalo sie wykonac translacji drona"<<endl;}
	  if(!woda.translacja(kat, licz)){cerr<<"Blad translacji wody"<<endl;}
	  if(!dno.translacja(kat, licz)){ cerr << "Blad translacji dna" << endl; }


	}
      }
      else{
	if(!dron.przesun(kat, licz+1)){cerr<<"Nie udalo sie wykonac translacji drona"<<endl;}
	if(!woda.translacja(kat, licz+1)){cerr<<"Blad translacji wody"<<endl;}
	if(!dno.translacja(kat, licz+1)){cerr<<"Blad translacji dna"<<endl;}

      }

      if(!lacze.DodajNazwePliku("dno.dat")){cerr<<"Nie udalo sie dodac nazwy pliku"<<endl;}
      if(!lacze.DodajNazwePliku("woda.dat")){cerr<<"Nie udalo sie dodac nazwy pliku"<<endl;}
      if(!lacze.DodajNazwePliku("prostopadloscian.dat")){cerr<<"Nie udalo sie dodac nazwy pliku"<<endl;}
      if(!lacze.DodajNazwePliku("lWirnik.dat")){cerr<< "Nie udalo sie dodac nazwy pliku" <<endl;}
      if(!lacze.DodajNazwePliku("pWirnik.dat")){cerr<< "Nie udalo sie dodac nazyw pliku" <<endl;}

       ileLacznie += dron.wezKadlub().wezWierzcholkiGlob().size() + woda.wezWierzcholkiGlob().size() + dno.wezWierzcholkiGlob().size();
      if(!lacze.Rysuj()){cout<<"Nie udalo sie narysowac sceny"<<endl;}
      
    }
    if(dron.wezKadlub().napotkano_wode()) { cerr <<endl<< "Nastapilo wynurzenie" << endl; }
    if(dron.wezKadlub().napotkano_dno()) { cerr << "Nastapilo uderzenie w dno" << endl; }
        
}

void Scena::obrocDrona(){
  double kat;
   cout << "Podaj wartosc kata obrotu w stopniach"<<endl;
    cout << "Wartosc kata<";
    cin >> kat;
    if(cin.fail()){
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "Nieznana wartosc" << endl;
    }
    for(int licznik=0; licznik<kat; licznik++){
      if(!dron.obrot(licznik+1)){cerr<<"Nie udalo sie wykonac rotacji drona"<<endl;}


      if(!lacze.DodajNazwePliku("prostopadloscian.dat")){cerr<<"Nie udalo sie dodac nazwy pliku"<<endl;}
      if(!lacze.DodajNazwePliku("lWirnik.dat")){cerr<<"Nie udalo sie dodac nazwy pliku"<<endl;}
      if(!lacze.DodajNazwePliku("pWirnik.dat")){cerr<<"Nie udalo sie dodac nazwy pliku" <<endl;}

       ileLacznie += dron.wezKadlub().wezWierzcholkiGlob().size() + woda.wezWierzcholkiGlob().size() + dno.wezWierzcholkiGlob().size();
      if(!lacze.Rysuj()){cerr<<"Nie udalo sie narysowac sceny"<<endl;}
    }
    
}



Scena::Scena(){
  
  lacze.UstawZakresX(-20,20);
  lacze.UstawZakresY(-20,20);
  lacze.UstawZakresZ(-20,20);


  if(!dron.wezKadlub().ustawPoczWsp("prostopadloscianLok.dat", "prostopadloscian.dat")){cerr<<"Nie udalo sie ustawic wspolrzednych globalnych kadluba"<<endl;}
  if(!dron.wezLWirnik().ustawPoczWsp("lWirnikLok.dat", "lWirnik.dat")){ cerr << "Nie udalo sie ustawic wspolrzednych globalnych lewego wirnika"<<endl;}
  if(!dron.wezPWirnik().ustawPoczWsp("pWirnikLok.dat", "pWirnik.dat")){ cerr << "Nie udalo sie ustawic wspolrzednych globalnych prawego wirnika"<<endl;}
  if(!woda.ustawPoczWsp("wodaLok.dat", "woda.dat")){ cerr<< "Nie udalo sie ustawic wspolrzednych globalnych wody" << endl; }
  if(!dno.ustawPoczWsp("dnoLok.dat", "dno.dat")){ cerr<<"Nie udalo sie ustawic wspolrzednych globalnych dna"<<endl; }
  ustawPrzeszkody();

  lacze.UstawRotacjeXZ(80,50);
  lacze.ZmienTrybRys(TR_3D);
  lacze.Inicjalizuj();

  ileAktualnie = dron.wezKadlub().wezWierzcholkiGlob().size() + woda.wezWierzcholkiGlob().size() + dno.wezWierzcholkiGlob().size();
  ileLacznie = ileAktualnie;
  
  if(!lacze.DodajNazwePliku("woda.dat")){ cerr << "Nie dodano nazwy pliku" << endl; }
  if(!lacze.DodajNazwePliku("dno.dat")){ cerr <<"Nie dodano nazwy pliku"<<endl; }
  if(!lacze.DodajNazwePliku("prostopadloscian.dat")){cerr <<"Nie dodano nazwy pliku"<<endl;}
  if(!lacze.DodajNazwePliku("lWirnik.dat")){cerr<< "Nie dodano nazwy pliku" << endl;}
  if(!lacze.DodajNazwePliku("pWirnik.dat")){cerr<< "Nie dodano nazwy pliku" << endl;}
  
  if(!lacze.Rysuj()){cout<<"blad"<<endl;}
}
