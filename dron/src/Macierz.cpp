#include "Macierz.hh"
using namespace std;
/*!
 * \file
 * \brief Plik zawiera definicje metod klasy \p Matrix
 */

Vector Matrix::operator * (Vector v)const{
    Vector nV;
     for(int i=0;i<SIZE;i++){
        for(int j=0; j<SIZE; j++){
            nV[i] += v[j]*board[i][j];
        }
     }
     return nV;
}

Matrix Matrix::switchColumn(int c, Vector v)const{
    Matrix nM;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            nM(i,j) = board[i][j];
        }
    }
    for(int i=0;i<SIZE;i++){
        nM(i,c) = v[i];
    }
    return nM;
}


double Matrix::det()const{
    Matrix helpM;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            helpM(i,j) = board[i][j];
        }
    }
    double result = 1;
    for(int i=0; i<SIZE-1;i++){
        for(int j=i+1;j<SIZE;j++){
            for(int k=i+1;k<SIZE;k++){
                helpM(j,k) = helpM(j,k) - (helpM(j,i)/helpM(i,i))*helpM(i,k);
            }
        }
    }
    for(int i=0;i<SIZE;i++){
        result *= helpM(i,i);
    }
    return result;
}

Matrix::Matrix(void){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board[i][j]=0;
        }
    }
}


 istream & operator >> (istream &in, Matrix &arr){
     for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            in >> arr(i,j);
	    if(in.fail()){
	      cerr<<"Wczytywanie macierzy nie powiodlo sie"<<endl;
	      return in;
	    }
        }
     }
     return in;
 }

 ostream & operator << (ostream &out, const Matrix &arr){
     out<<"\n";
     for(int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            out<<arr(i,j)<<" ";
        }
        out<<endl;
     }
     return out;
 }
