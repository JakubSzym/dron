#include "PowierzchniaWody.hh"

/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p PowierzchniaWody
*/

using namespace std;

bool PowierzchniaWody::translacja(double alpha, double r){
  Vector wektorT;
  wektorT[0] = r*cos(alpha*(M_PI/180));
  wektorT[1] = 0;
  wektorT[2] = 0;

  bool odczytano = czytajWspLok("wodaLok.dat");
  
  if(odczytano){
    for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
      wierzcholkiGlob[i] = wierzcholkiLok[i] + wektorT;
    }
  }else{
    return false;
  }
  
  bool zapis = zapiszWspGlob("woda.dat");
  return zapis;
}
