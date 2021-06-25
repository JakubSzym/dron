#ifndef MACIERZRORACJI_HH
#define MACIERZROTACJI_HH

#include "Macierz.hh"

/*!
 * \file
 * \brief Klasa modeluje macierz rotacji
*/

class MacierzRotacji: public Matrix{
public:
  /*!
   *\brief konstruktor Macierzy rotacji
   *Argumenty:
   *  \p katRot - kat rotacji
*/
  MacierzRotacji(double katRot);
};

#endif //MACIERZROTACJI_HH