#include "MacierzRotacji.hh"
#include <cmath>

/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p MacierzRotacji
*/

using namespace std;

MacierzRotacji::MacierzRotacji(double katRot){
  board[0][0] = cos(katRot);
  board[0][1] = sin(katRot);
  board[0][2] = 0;
  board[1][0] = -1*sin(katRot);
  board[1][1] = cos(katRot);
  board[1][2] = 0;
  board[2][0] = 0;
  board[2][1] = 0;
  board[2][2] = 1;
}