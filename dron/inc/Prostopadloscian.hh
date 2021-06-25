#ifndef PROSTPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH



#include "Figura.hh"
#include "MacierzRotacji.hh"
#include "PowierzchniaWody.hh"
#include "PowierzchniaDna.hh"

/*!
 * \file
 * \brief Klasa modeluje pojecie prostopadloscianu
 *Dziedziczy z klasy \p Figura
*/

class Prostopadloscian: public Figura{
public:

  /*!
   * \brief metoda pozwala na obrot prostopadloscianu wokol osi Z
   *Argumenty:
   *  \p kat - kat obrotu (w stopniach)
   *Zwraca:
   *  \p true - jezeli rotacja sie powiodla
   *  \p false - jezeli sie nie udala
*/
  bool rotacja(double kat);

  /*!
   * \brief metoda wirtualna dziedziczona z WspGlobalne
   * pozwala na przesuniecie prostopadlosianu na odleglosc r
   * pod katem alpha ( kat wzgledem osi X, w stopniach)
   *Argumenty:
   *  \p alpha - kat translacji
   *  \p r - odleglosc
   *Zwraca:
   *  \p true - jezeli translacja sie powiodla
   *  \p false - jezeli sie nie powiodla
*/
  bool translacja(double alpha, double r);

  /*!
   * \brief metoda sprawdza, czy prostopadloscian wynurzyl sie na powierzchnię wody
   * Zwraca:
   *  \p true - jezel sie wynurzyl
   *  \p false - jezeli sie nie wynurzyl
*/
  bool napotkano_wode();

  /*!
   * \brief metoda sprawdza, czy prostopadloscian zderzyl sie z dnem
   * Zwraca:
   *  \p true - jezeli sie zderzyl
   *  \ false - jezeli sie nie zderzyl
*/
  bool napotkano_dno();
 

  /*!
   * \brief konstuktor
*/
  Prostopadloscian(){}
  /*!
   * \brief destruktor
*/
  ~Prostopadloscian(){}

};
#endif //PROSTOPADLOSCIAN_HH
