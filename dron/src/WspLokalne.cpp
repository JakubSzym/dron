#include "WspLokalne.hh"

/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p WspLokalne
*/
using namespace std;

bool WspLokalne::czytajWspLok(const char* nazwaPliku){
  ustawNazwe(nazwaPliku);

  fstream plikWspLok;
  Vector wektorP;
  
  plikWspLok.open(nazwaWspLok, ios::in);
  if(!plikWspLok.is_open()){return false;}
  
  do{
    plikWspLok >> wektorP;
    wierzcholkiLok.push_back(wektorP);
  }while(!plikWspLok.eof());
  return true;
}

Vector WspLokalne::srodekMasyLok(){
  Vector sumaWek, srodek;
  
  for(unsigned int i=0; i<wierzcholkiLok.size(); i++){
    sumaWek += wierzcholkiLok[i];
  }
  srodek = sumaWek/wierzcholkiLok.size();
  return srodek;
}