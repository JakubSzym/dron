#ifndef KOSTKA_HH
#define KOSTKA_HH

#include "Figura.hh"

/*!
 * \file \brief definicja klasy Kostka
*/

class Kostka: public Figura{
public:
  /*!
   * \brief metoda zawsze zwraca false, aby nie mona byo przesuwac takich kostek
*/
  bool translacja(double alpha, double r){ return false;}
  /*!
   * \brief konstruktor
*/
  Kostka(){}
  /*!
   * \brief destruktor
*/
  ~Kostka(){}
};

#endif //KOSTKA_HH