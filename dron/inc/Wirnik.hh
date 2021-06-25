#ifndef WIRNIK_HH
#define WIRNIK_HH

#include "Figura.hh"

/*!
 * \file \brief
 * Plik zawiera deklaracje klasy Wirnik
*/

class Wirnik: public Figura{
  /*!
   * \brief okresla z ktorym wirnikiem mamy do czynienia
*/
  char ktory;
public:
  /*!
   * \brief Zwraca przez referecje zmienna prywatną \p ktory
*/
  char & Ktory() { return ktory;}

  /*!
   * obraca wirnik wokół środka masy
   * Argumenty:
   *   \p alpha - kat obrotu
   * Zwraca:
   *   \p true - jezeli rotacja sie udala
   *   \p false - jezeli sie nie udala
*/
  bool rotacjaSrM(double alpha);

  /*!
   * \brief obraca wirnik wokół osi Z
   * Argumenty:
   *   \p alpha - kat obrotu
   * Zwraca:
   *   \p true - jezeli rotacja sie udala
   *   \p false - jezeli sie nie udala
*/
  bool rotacja(double alpha);

  /*!
   * \brief przesuwa wirnik na zadaną odleglosc z zadanym katem wznoszenia/opadania
   * Argumenty:
   *   \p alpha - kat wznoszenia/opadania
   *   \p r - odleglosc
   * Zwraca:
   *  \p true - jezeli translacja sie udala
   *  \p false - jezeli translacja sie nie udala
*/
  bool translacja(double alpha, double r);

  /*!
   * \brief konstruktor
*/
  Wirnik(){}
  /*!
   * \brief destruktor
*/
  ~Wirnik(){}
};
#endif