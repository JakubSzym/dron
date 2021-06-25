#include "Figura.hh"

/*!
 * \file
 * \brief Plik zawiera definicje metod klasy WspGlobalne
*/

using namespace std;


bool Figura::zapiszWspGlob(const char* nazwaPliku){
  ustawNazweGlob(nazwaPliku);

  fstream plikWspGlob;
  plikWspGlob.open(nazwaWspGlob, ios::out);
  if(!plikWspGlob.is_open()){ return false; }

  for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
    if(i%4==0){
      plikWspGlob << endl;
    }
    plikWspGlob << wierzcholkiGlob[i]<<endl;
  }
  plikWspGlob.close();
  return true;
}

bool Figura::ustawPoczWsp(const char* nazwaLok, const char* nazwaGlob){
  fstream plikLok;
  fstream plikGlob;

  ustawNazwe(nazwaLok);
  ustawNazweGlob(nazwaGlob);

  bool odczytano = czytajWspLok(nazwaLok);
  
  if(!odczytano){return false;}
  plikLok.open(nazwaLok, ios::in);
  plikGlob.open(nazwaGlob, ios::out);

  if(!plikLok.is_open() || !plikGlob.is_open() ){return false;}

  for(unsigned int i=0; i<wierzcholkiLok.size(); i++){
    if(i!=0 && i%4==0){
      plikGlob << endl;
    }
    plikGlob << wierzcholkiLok[i] << endl;
  }

  wierzcholkiGlob = std::vector<Vector>(wierzcholkiLok.size());
  
  return !plikLok.fail() && !plikGlob.fail();
}

Vector Figura::srodekMasyGlob(){
  Vector sumaWek, srodek;

  for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
    sumaWek += wierzcholkiGlob[i];
  }
  srodek = sumaWek/wierzcholkiLok.size();
  return srodek;
}