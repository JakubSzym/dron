#ifndef SCENA_HH
#define SCENA_HH

#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Kostka.hh"
#include "Pret.hh"
#include "Powierzchnia.hh"

#include <unistd.h>

/*!
 * \file
 *\brief Klasa modeluje scene, na ktorej znajduje sie obiekty
*/

class Scena{
  /*!
   * \brief modeluje powierzchnie wody
*/
  PowierzchniaWody woda;
  /*!
   * \brief modeluje powierzchnie dna
*/
  PowierzchniaDna dno;
  /*!
   * \brief modeluje drona podwodnego
*/
  Dron dron;
  /*!
   * \brief dynamiczna tablica przeszkod
*/
  std::vector<Figura*> przeszkody;
  /*!
   * \brief lacze do programu \p gnuplot
*/
  PzG::LaczeDoGNUPlota lacze;

public:
  /*!
   * \brief liczba wierzcholkow na scenie w danym momencie
*/
  static unsigned int ileAktualnie;
  /*!
   * \brief laczna liczba wierzcholkow na scenie w ciagu calej pracy programu
*/
  static unsigned int ileLacznie;
  /*!
   * \brief ustawia przeszkody na scenie
*/
  void ustawPrzeszkody();

  /*!
   * \brief Wyswietla menu
*/
  void wyswietlMenu();
  /*!
   * \brief Obraca dronem o zadany kat wokol osi Z
*/
  void obrocDrona();

  /*!
   * \brief Przesuwa drona o zadany kat i odleglosc
*/
  void przesunDrona();

  /*!
   * \brief konstruktor
*/
  Scena();
};


#endif //SCENA_HH