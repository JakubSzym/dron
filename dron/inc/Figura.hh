#ifndef FIGURA_HH
#define FIGURA_HH

#include "WspLokalne.hh"

/*!
 * \file
 * \brief Klasa przechowuje informacje o wspolrzednych globalnych
 * i wykonuje na nich operacje
 *Dziedziczy z klasy \p WspLokalne
*/

class Figura: public WspLokalne{
private:
  /*!
   * \brief nazwa pliku, do ktorego zapisujemy wspolrzedne globalne
*/
  const char* nazwaWspGlob;
protected:
  /*!
   * \brief dynamiczna tablica, w ktorej przechowywane sa wierzcholki globalne
   * w postaci obiektow typu Vector
*/
  std::vector<Vector> wierzcholkiGlob;

  /*!
   *\brief metoda ustawia nazwe pliku, do ktorego bedziemy zapisywac
*/
  void ustawNazweGlob(const char* nazwa){ nazwaWspGlob = nazwa; }

  Vector predkosc;

public:
  /*!
   * \brief metoda oblicza środek masy w układzie globalnym
   * Zwraca:
   * obiekt klasy Vector zawierający odpowiednie współrzędne
*/
  Vector srodekMasyGlob();

  /*!
   * \brief metoda zapisuje wspolrzedne globalne do pliku
   *Argumenty:
   * \p nazwaPliku
   *Zwraca:
   *  \p true - jezeli udalo sie zapisac
   *  \p false - jezeli nie udalo sie zapisac
*/
  bool zapiszWspGlob(const char* nazwaPliku);

  /*!
   * \brief metoda ustawia wyjsciowe wspolrzedne globalne
   *Argumenty:
   *  \p nazwaLok - plik ze wspolrzednymi lokalnymi
   *  \p nazwaGlob - plik, do ktorego zapisujemy wspolrzedne globalne
*/
  bool ustawPoczWsp(const char* nazwaLok, const char* nazwaGlob);

  /*!
   * \brief metoda pozwala na dostep do pola wierzcholkiGlob poza klasa i klasami pochodnymi
   *Zwraca:
   *  tablice dynamiczna \p wierzcholkiGlob - przez referencje
*/
  std::vector<Vector> & wezWierzcholkiGlob(){ return wierzcholkiGlob; }

  /*!
   * \brief metoda czysto wirtualna, jej specjalizacje sa opisane w odpowiednich klasach pochodnych
*/
  virtual bool translacja(double alpha, double r) = 0;

  /*!
   * \brief destruktor wirtualny
*/
  virtual ~Figura(){}
};

#endif //WSPGLOBALNE_HH
