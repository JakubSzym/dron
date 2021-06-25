#include "PowierzchniaDna.hh"
#include <cmath>

/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p PowierzchniaDna
*/

using namespace std;

bool PowierzchniaDna::translacja(double alpha, double r){
  Vector wektorT;
  wektorT[0] = r*cos(alpha*(M_PI/180));
  wektorT[1] = 0;
  wektorT[2] = 0;

  bool odczytano = czytajWspLok("dnoLok.dat");

  if(odczytano){
    for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
      wierzcholkiGlob[i] = wierzcholkiLok[i] + wektorT;
    }
  }else{
    return false;
  }
  
  bool zapis = zapiszWspGlob("dno.dat");
  return zapis;
}
