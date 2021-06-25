#ifndef DRON_HH
#define DRON_HH

#include "Wirnik.hh"
#include "Prostopadloscian.hh"

/*!
 * \file \brief Plik zawiera deklaracje i opis metod klasy Dron
*/


class Dron{
private:
  /*! \brief modeluje kadlub drona*/
  Prostopadloscian kadlub;
  /*!
   * modeluje jeden z wirników drona
*/
  Wirnik lWirnik;
  /*!
   * modeluje jeden z wirników drona
*/
  Wirnik pWirnik;

public:
  /*!
   * \breif Zwraca jeden z wirników drona
*/
  Wirnik & wezLWirnik() { return lWirnik;}

  /*!
   * \brief Zwraca jeden z wirników drona
*/
  Wirnik & wezPWirnik() { return pWirnik;}

  /*!
   * \brief Zwraca kadlub drona
*/
  Prostopadloscian & wezKadlub(){ return kadlub; }

  /*!
   * \brief metoda obraca drona wokó osi Z
   * Argumenty:
   *  \p alpha - kat obrotu
   * Zwraca:
   *  \p true - jezeli udalo sie obrocic drona
   *  \p false - jezeli sie nie udalo
*/
  bool obrot(double alpha);

  /*!
   * \brief przesuwa drona o zadan odlegos z zadanym katem wznoszenia/opadania
   * Argumenty:
   *  \p alpha - kat wznoszenia/opadania
   *  \p r - zadana odleglosc
   * Zwraca:
   *  \p true - jezeli udalo sie przesunc drona
   *  \p false - jezeli nie udalo sie przesunac drona
*/
  bool przesun(double alpha, double r);


  /*!
   * \brief konstruktor
*/
  Dron();
  /*!
   * destruktor
*/
  ~Dron(){}
};

#endif //DRON_HH
