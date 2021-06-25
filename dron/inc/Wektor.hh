#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <cmath>
#include<iostream>

#define SIZE 3

/*
 * \file
 *  \brief Klasa modeluje pojêcie wektora o wymiarze \p SIZE
 * Dla tej klasy przeci¹zono operator indeksowania,
 * aby mo¿na by³o swobodnie operowaæ na wspó³rzêdnych
 * wektora.
 * Zdefiniowano tez nastêpujace metody:
 *  \p len - pozwala policzyæ d³ugoœæ wektora
 *  operator dodawania - dodawanie dwóch wektorów
 *  operator odejmowania - odejmowanie dwóch wektorów
 *  operator mno¿enia - mno¿enie przez liczbê lub liczenie iloczynu skalarnego
 *  operator dzielenia - dzielenie przez liczbê
 *  \p Vector - konstruktor klasy
 */
class Vector{
   double myArray[SIZE];
  public:
    /*!
     * \brief Przeciazono operator indeksowania, aby móc swobodnie
     *odnosiæ sie do współrzêdnych wektora
     *Argumenty:
     *  \p index - indeks współrzêdnej wektora
     *Zwraca:
     *  odpowiednia współrzêdna wektora
    */
    double operator [](int index) const {
        return myArray[index];
    }
    /*!
     * \brief Przeciazono operator indeksowania, aby móc swobodnie
     *odnosiæ sie do współrzêdnych wektora
     *Argumenty:
     *  \p index - indeks współrzêdnej wektora
     *Zwraca:
     *  odpowiednia współrzêdna wektora
    */
    double & operator [](int index){
        return myArray[index];
    }
    /*!
    * \brief Oblicza d³ugoœæ wektora
    * D³ugoœæ liczona jest jako pierwiastek kwadratowy iloczynu
    * skalarnego dwóch równych sobie wektorów
    * Zwraca:
    *    d³ugosc wektora jako zmienn¹ typu \p double
    */
   double len()const{
     return sqrt((*this)*(*this));
   }
   /*!
   * \brief Realizuje dodawanie dwóch wektorów
   * Argumenty:
   *    obiekt klasy wektor, na którym pracuje
   *    \p v2 - obiekt klasy \p Vector
   * Zwraca:
   *    obiekt klasy \p Vector
   */
   Vector operator + (const Vector v2);
   /*!
   * \brief Realizuje odejmowanie dwóch wektorów
   * Argumenty:
   *    obiekt klasy \p Vector, na którym pracuje
   *    \p v2 - obiekt klasy \p Vector
   * Zwraca:
   *    obiekt klasy \p Vector
   */
   Vector operator - (const Vector v2);
   /*!
   * \brief Realizuje mnozenie skalarne dwóch wektorów
   * Argumenty:
   *    obiekt klasy \p Vector, na którym pracuje
   *    \p v2 - obiekt klasy \p Vector
   * Zwraca:
   *    obiekt klasy \p Vector
   */
   double operator * (const Vector v2)const;
   /*!
   * \brief Realizuje mnozenie  wektora przez liczbe
   * Argumenty:
   *    obiekt klasy \p Vector, na którym pracuje
   *    \p number - liczba typu \p double
   * Zwraca:
   *    obiekt klasy \p Vector
   */
   Vector operator * (double number);
    /*!
   * \brief Realizuje dzielenie  wektora przez liczbe
   * Argumenty:
   *    obiekt klasy \p Vector, na którym pracuje
   *    \p number - liczba typu \p double
   * Zwraca:
   *    obiekt klasy \p Vector
   */
   Vector operator / (double number);

  Vector & operator += (const Vector v2);
  /*!
   *\brief konstruktor
*/
   Vector(void);
};


/*!
* \brief Realizuje wczytywanie obiektu klasy \p Vector w postaci
* kolejnych liczb oddzielonych białymi znakami
* Argumenty:
*   \p in - strumień wejściowy (przez referencję)
*   \p vec - obiekt klasy Vector (przez referencję)
* Zwraca:
*   strumień wejściowy otrzymany jako argument
 */
std::istream & operator >> (std::istream &in, Vector &vec);

/*!
*\brief  Realizuje wyświetlanie obiektu klasy \p Vector w postaci
* kolejnych liczb oddzielonych spacjami
* Argumenty:
*   \p out - strumień wyjściowy (przez referencję)
*   \p vec - obiekt klasy \p Vector (przez referencję)
* Zwraca:
*   strumień wyjściowy otrzymany jako argument
 */
std::ostream & operator << (std::ostream &out, const Vector &vec);

#endif //WEKTOR_HH