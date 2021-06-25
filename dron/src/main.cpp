#include "Scena.hh"

/*!
 * \file
 * \brief Plik zawiera funkcje \p main()
*/

#define MENU 'm'
#define RUCH 'r'
#define OBROT 'o'
#define KONIEC 'k'

using namespace std;

unsigned int Scena::ileLacznie;
unsigned int Scena::ileAktualnie;

int main(){
  Scena scena;

  char wybor = ' ';

  while(wybor != KONIEC){
    cout<<"Twoj wybor, m - menu<";
    cin >> wybor;
    switch(wybor){
    case MENU:
    scena.wyswietlMenu();
      break;
    case RUCH:
      scena.przesunDrona();
      break;
    case OBROT:
      scena.obrocDrona();
      break;
    case KONIEC:
      cout << "Koniec programu" << endl;
      break;
    default:
      cerr << "Nie ma takiej opcji"<<endl;
    }
  }

  return 0;
}