#ifndef POWIERZCHNIAWODY_HH
#define POWIERZCHNIAWODY_HH

#include "Figura.hh"

/*! 
 *\file 
 * \brief Klasa modeluje pojcie powierzchni wody. Dziedziczy z klasy Figura
*/

class PowierzchniaWody: public Figura{
public:
  /*!
   *\brief stala wartosc sredniego poziomu wody
*/
  static const int POZIOM_WODY = 14;

  /*!
   * \brief metoda pozwala na przesuniecie plaszczyzny na wprost
   * Przyjmuje jako argumenty "wspolrzedne biegunowe", ktore
   * sa przeliczane na wektor translacji
   *Argumenty:
   *  \p alpha - kat translacji
   *  \p r - odleglosc
*/
  bool translacja(double alpha, double r);

  /*!
   *\brief konstruktor
*/
  PowierzchniaWody(){}
  /*!
   * \brief destruktor
*/
  ~PowierzchniaWody(){}
};


#endif //POWIERZCHNIAWODY_HH
