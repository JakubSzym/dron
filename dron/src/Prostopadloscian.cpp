#include "Prostopadloscian.hh"
#include <cmath>

/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p Prostopadloscian
*/

using namespace std;

bool Prostopadloscian::rotacja(double kat){

  kat = kat*(M_PI/180);
  
  MacierzRotacji MacRot(kat);
  bool odczytano = czytajWspLok("prostopadloscianLok.dat");
  
  if(odczytano){
    for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
      wierzcholkiGlob[i]  = MacRot*wierzcholkiLok[i];
    }
  }
  else{
    cerr<<"Blad odczytu"<<endl;
    return false;
  }
  
  bool zapisano = zapiszWspGlob("prostopadloscian.dat");
  return zapisano;
}

bool Prostopadloscian::translacja(double alpha, double r){
  Vector wektorT;
  alpha = alpha*(M_PI/180);
  wektorT[0] = r*cos(alpha);
  wektorT[1] = 0;
  wektorT[2] = r*sin(alpha);
  
  bool odczytano = czytajWspLok("prostopadloscianLok.dat");
  
  if(odczytano){
    for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
      wierzcholkiGlob[i] = wierzcholkiLok[i] + wektorT;
    }
  }
  else{
    return odczytano;
  }
  
  bool zapisano = zapiszWspGlob("prostopadloscian.dat");
  return zapisano;
}

bool Prostopadloscian::napotkano_wode(){
  for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
    if(wierzcholkiGlob[i][2] >= PowierzchniaWody::POZIOM_WODY){
      return true;
    }
  }
  return false;
}

bool Prostopadloscian::napotkano_dno(){
  for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
    if(wierzcholkiGlob[i][2] <= PowierzchniaDna::POZIOM_DNA){
      return true;
    }
  }
  return false;
}
