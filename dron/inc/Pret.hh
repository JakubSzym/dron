#ifndef PRET_HH
#define PRET_HH

#include "Figura.hh"

/*!
 * \file \brief Plik zawiera definicje klasy Pret
*/

class Pret: public Figura{
public:
  /*!
   * \brief metoda zawsze zwraca false, aby nie można było przesuwac takich pretow
*/
  bool translacja(double alpha, double r){return false;}
  /*!
   * \brief konstruktor
*/
  Pret(){}
  /*!
   * \brief destruktor
*/
  ~Pret(){}
};

#endif