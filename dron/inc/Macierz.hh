#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"


/*!
 * \file
* \brief Klasa modeluje pojêcie macierzy - prostokatnej tablicy liczb
* \p SIZE oznacza wymiar macierzy. Przez tê klasê mozemy modelowac jedynie
* macierze kwadratowe
* Dla tej klasy przeci¹¿ono operator funckyjny, aby mo¿na by³o ³atwo
* dostaæ siê do odpowiedniego pola macierzy.
* Zdefiniowano tak¿e metody, które pozwalaja operowac na macierzy:
*   Operator mnozenia - mno¿enie macierzy przez wektor
*  \p  switchColumn - zamiana jednej kolumny macierzy na wektor
*   \p det - obliczanie wyznacznika macierzy
*   \p Matrix - konstruktor
 */
class Matrix {
protected:
   double board[SIZE][SIZE]; //modeluje kwadratow¹ tablice liczb
  public:
      /*!
       *
       * \brief Przeciazono operator funkcyjny,
       *aby mo¿na bylo siê nim poslugiwac w ró¿nych sytuacjach.
       * Umo¿liwia to swobodne odwolywanie siê do pól macierzy
       * Argumenty:
       *   \p row - wiersz macierzy
       *   \p column - kolumna macierzy
       *Zwraca:
       *  liczbê z macierzy o odpowiednich wspólrzêdnych
      */
    double operator ()(int row, int column) const{
        return board[column][row];
    }
    /*!
       *
       * \brief Przeciazono operator funkcyjny,
       *aby mo¿na bylo siê nim poslugiwac w ró¿nych sytuacjach.
       * Umo¿liwia to swobodne odwolywanie siê do pól macierzy
       * Argumenty:
       *   \p row - wiersz macierzy
       *   \p column - kolumna macierzy
       *Zwraca:
       *  liczbê z macierzy o odpowiednich wspólrzêdnych
      */
    double & operator ()(int row, int column){
        return board[column][row];
    }
    /*!
     *\brief Metoda pozwala na mnozenie macierzy przez wektor.
     *Algorytm opiera siê na arytmetyce macierzy.
     *Argumenty:
     *  \p v - obiekt typu \p Vector
     *Zwraca:
     *  Wynikiem mno¿enie macierzy przez wektor jest
     *  zawsze wektor, zatem metoda zwraca obiekt typu
     *  \p Vector
    */
    Vector operator * (const Vector v)const;
    /*!
     *\brief Zamienia wybranz kolumnê macierzy na wektor.
     *Metoda tworzy nowa macierz - nie zmienia stanu
     *obiektu na którym pracuje
     *Argumenty:
     *  \p c - numer kolumny: wartoœci od \p 0 do \p SIZE-1
     *  \p v - obiekt typu \p Vector
    */
    Matrix switchColumn(int c, Vector v)const;
    /*!
     *\brief Oblicza wyznacznik macierzy kwadratowej,
     *korzystaj¹c z algorytmem eliminacji Gaussa.
     *Doprowadza macierz do macierzy trójkatnej,
     *co ulatwia liczenie wyznacznika
     *Metoda nie zmienia stanu obiektu, na którym pracuje
     *Zwraca:
     *  zmienna typu \p double
    */
   double det()const;
   /*!
    *\brief Konstruktor klasy
    *Wypełnia tablicę obiektu zerami
   */
   Matrix(void);
};


/*!
* \brief Przeciazenie operatora wejścia dla klasy Matrix
* Wczytuje macierz w postaci kwadratowej tablicy liczb.
* Zaleca siê wprowadzanie w postaci transponowanej
* Argumenty:
*   \p in - strumieñ wejœciowy (przez referencjê)
*   \p arr - obiekt klasy Matrix (przez referencjê)
* Zwraca:
*   strumieñ wejœciowy, przes³any jako argument przez referencjê
 */
std::istream& operator >> (std::istream &in, Matrix &arr);

/*!
* \brief Przeci¹¿enie operatora wyjœcia dla klasy \p Matrix
* Wyswietla macierz w postaci kwadratowej tablicy liczb
* Argumenty:
*   \p out - strumieñ wyjœciowy (przez referencjê)
*   \p arr - obiekt klasy Matrix (przez referencjê)
* Zwraca:
*   strumieñ wyjœciowy podany jako argument funkcji
 */
std::ostream& operator << (std::ostream &out, const Matrix &arr);

#endif //MACIERZ_HH