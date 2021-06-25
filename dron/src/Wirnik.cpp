#include "Wirnik.hh"
#include "MacierzRotacji.hh"
using namespace std;

bool Wirnik::rotacjaSrM(double alpha){
  bool zapisano = false, odczytano = false;
  
  alpha = alpha*(M_PI/180);
  Vector wekT = srodekMasyLok() - srodekMasyGlob();
  MacierzRotacji MacRot(alpha);
  if(ktory == 'l'){
    odczytano = czytajWspLok("lWirnikLok.dat");
  }else if(ktory == 'p'){
    odczytano = czytajWspLok("pWirnikLok.dat");
  }
  
  if(odczytano){
    for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
      wierzcholkiGlob[i]  = MacRot*wierzcholkiLok[i] + wekT;
    }
  }
  else{
    cerr<<"Blad odczytu"<<endl;
    return false;
  }

  if(ktory == 'l'){
    zapisano = zapiszWspGlob("lWirnik.dat");
  }else if(ktory == 'p'){
    zapisano = zapiszWspGlob("pWirnik.dat");
  }
  return zapisano;
}

bool Wirnik::rotacja(double alpha){
  bool odczytano = false, zapisano = false;
  
  alpha = alpha*(M_PI/180);
  
  MacierzRotacji MacRot(alpha);
  if(ktory == 'l'){
  odczytano = czytajWspLok("lWirnikLok.dat");
  }else if(ktory == 'p'){
  odczytano = czytajWspLok("pWirnikLok.dat");
  }
  
  if(odczytano){
    for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
      wierzcholkiGlob[i]  = MacRot*wierzcholkiLok[i];
    }
  }
  else{
    cerr<<"Blad odczytu"<<endl;
    return false;
  }
  if(ktory == 'l'){
    zapisano = zapiszWspGlob("lWirnik.dat");
  }else if(ktory == 'p'){
    zapisano = zapiszWspGlob("pWirnik.dat");
  }
  return zapisano;
}

bool Wirnik::translacja(double alpha, double r){
  bool odczytano = false, zapisano = false;
  
  Vector wektorT;
  alpha = alpha*(M_PI/180);
  wektorT[0] = r*cos(alpha);
  wektorT[1] = 0;
  wektorT[2] = r*sin(alpha);

  if(ktory == 'l'){
    odczytano = czytajWspLok("lWirnikLok.dat");
  }else if(ktory == 'p'){
    odczytano = czytajWspLok("pWirnikLok.dat");
  }
  
  if(odczytano){
    for(unsigned int i=0; i<wierzcholkiGlob.size(); i++){
      wierzcholkiGlob[i] = wierzcholkiLok[i] + wektorT;
    }
  }
  else{
    return odczytano;
  }
  if(ktory == 'l'){
    zapisano = zapiszWspGlob("lWirnik.dat");
  }else if(ktory == 'p'){
    zapisano = zapiszWspGlob("pWirnik.dat");
  }
  return zapisano;
}
