#ifndef WSPLOKALNE_HH
#define WSPLOKALNE_HH

#include "Wektor.hh"

#include<cwctype>
#include<fstream>
#include<vector>
#include<string>

/*!
 * \file
 * \brief Klasa przechowuje informacje o wspolrzednych lokalnych
 * i wykonuje na nich operacje
*/

class WspLokalne{
private:
  /*!
   * \brief nazwa pliku, z ktorego czytamy wzorcowe wspolrzedne
*/
  const char* nazwaWspLok;
protected:

  /*!
   * \brief Dynamiczna tablica wektorow
   *przechowuje wierzcholki lokalne w postaci obiektow typu \p Vector
*/
  std::vector<Vector> wierzcholkiLok;

  /*!
   * \brief metoda ustawia nazwe pliku, z ktorego bedziemy czytac
*/
  void ustawNazwe(const char* nazwa) {nazwaWspLok = nazwa;}
public:
  /*!
   * \brief metoda oblicza srodek masy obiektu w ukladzie globalnym
   *Zwraca:
   *  obiekt klasy Vector zawierajcy odpowiednie wspórzdne
*/
  Vector srodekMasyLok();

  /*!
   * \brief metoda czyta wspolrzedne z pliku i zapisuje je do dynamicznej tablicy
   *Argumenty:
   *  \p nazwaPliku
   *Zwraca:
   * \p true - jezeli udalo sie odczytac
   * \p false - jezeli nie udalo sie odczytac
*/
  bool czytajWspLok(const char* nazwaPliku);
  /*!
   *\brief metoda zwraca tablic dynamiczn ze wspórzdnymi lokalnymi
*/
  std::vector<Vector> & wezWierzcholkiLok(){ return wierzcholkiLok;}
};

#endif //WSPLOKALNE_HH