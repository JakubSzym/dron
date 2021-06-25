#include "Wektor.hh"
using namespace std;
/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p Vector
 */

 Vector Vector::operator + (const Vector v){
       Vector nV;
       for(int i=0; i<SIZE; i++){
        nV[i] = myArray[i] + v[i];
       }
       return nV;
 }
 Vector Vector::operator - (const Vector v){
       Vector nV;
       for(int i=0; i<SIZE; i++){
        nV[i] = myArray[i] - v[i];
       }
       return nV;
 }
 double Vector::operator * (const Vector v)const{
     double product=0;
     for(int i=0; i<SIZE; i++){
        product += myArray[i]*v[i];
     }
     return product;
 }
 Vector Vector::operator * (double number){
     for(int i=0; i<SIZE; i++){
        myArray[i] *= number;
     }
     return *this;
 }

 Vector Vector::operator / (double number){
     for(int i=0; i<SIZE; i++){
        myArray[i] /= number;
     }
     return *this;
 }

Vector& Vector::operator+=(const Vector v2){
  for(int i=0; i<SIZE; i++){
    myArray[i] += v2[i];
  }
  return *this;
}
 Vector::Vector(void){
     for(int i=0;i<SIZE;i++){
        myArray[i]=0;
     }
 }

istream & operator >> (istream &in, Vector &vec){
    for(int i=0; i<SIZE; i++){
        in >> vec[i];
	if(in.fail()){
	  cerr<<"Wczytywanie wektora nie powiodlo sie"<<endl;
	  return in;
	}
    }
    return in;
}

ostream & operator << (ostream &out, const Vector &vec){
    for(int i=0; i<SIZE; i++){
        out << vec[i] << " ";
    }
    return out;
}
