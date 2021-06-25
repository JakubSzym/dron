#ifndef POWIERZCHNIADNA_HH
#define POWIERZCHNIADNA_HH

#include "Figura.hh"

/*!
 * \file
 *\brief Klasa modeluje dno. Dziedziczy z klasy \p Figura
*/

class PowierzchniaDna: public Figura{
public:
  /*!
   *\brief stala przechowujaca poziom dna
*/
  static const int POZIOM_DNA = -13;

  /*!
   *\brief metoda pozwala na przesuniecie dna o wektor na wprost
   *Przyjmuje jako argumenty "wspolrzedne biegunowe",
   *ktore przelicza sie na wektor translacji
   * Argumenty:
   *   \p alpha - kat translacji
   *   \p r - odleglosc
   * Zwraca:
   *  \p true - jezeli translacja sie powiodla
   *  \p false - jezeli sie nie powiodla
*/
  bool translacja(double alpha, double r);

  /*!
   * \brief konstruktor
*/
  PowierzchniaDna(){}
  /*!
   * \brief destruktor
*/
  ~PowierzchniaDna(){}
};


#endif //POWIERZCHNIADNA_HH
