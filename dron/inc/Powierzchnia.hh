#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "Figura.hh"

/*!
 * Plik zawiera definicje klasy Powierzchnia
*/

class Powierzchnia: public Figura{
public:
  /*!
   * \brief metoda zwraca zawsze false, poniewaz nie mozna przesuwac takich powierzchni
*/
  bool translacja(double alpha, double r){return false;}
  /*!
   * \brief konstruktor
*/
  Powierzchnia(){}
  /*!
   * \brief destruktor
*/
  ~Powierzchnia(){}
};

#endif