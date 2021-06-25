#include "Dron.hh"

using namespace std;

bool Dron::przesun(double alpha, double r){
  if(!kadlub.translacja(alpha, r)) { return false; }
  if(!lWirnik.rotacjaSrM(alpha*2)) { return false; }
  if(!lWirnik.translacja(alpha, r)) {return false; }
  if(!pWirnik.rotacjaSrM(alpha*2)) { return false; }
  if(!pWirnik.translacja(alpha, r)) { return false; }

  return true;
}

bool Dron::obrot(double alpha){
  if(!kadlub.rotacja(alpha)) { return false; }
  if(!lWirnik.rotacjaSrM(alpha*2)) { return false; }
  if(!lWirnik.rotacja(alpha)) { return false; }
  if(!pWirnik.rotacjaSrM(alpha*2)) {return false; }
  if(!pWirnik.rotacja(alpha)) { return false; }

  return true;
}

Dron::Dron(){
  lWirnik.Ktory() = 'l';
  pWirnik.Ktory() = 'p';
}