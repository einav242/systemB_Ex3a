#include <string>
#include<vector>
#include <iostream>
#include <stdexcept>
using  namespace std;

namespace zich{
    class  Matrix {  
        public:
            vector<vector<double>> v;
            unsigned int row;
            unsigned int colum;   
        public:
            Matrix(std::vector<double> v,int r,int c){
                if(v.size()!=r*c)
                {
                    throw std::invalid_argument("the size of the vector is not good");
                }
                if(r<0 || c<0)
                {
                    throw std::invalid_argument("only positive number can be a row and colum");
                }
                this->row=(unsigned int)r;
                this->colum=(unsigned int)c;
                unsigned int k=0;
                this->v.assign(this->row,vector<double>(this->colum));
                for(unsigned int i=0;i<r;i++)
                {
                    for(unsigned int j=0; j<c;j++)
                    {
                        this->v[i][j]=v[k];
                        k++;
                    }
                }
                //   for(unsigned int i=0;i<r;i++)
                // {
                //     for(unsigned int j=0; j<c;j++)
                //     {
                //         cout<<this->v[i][j];
                //     }
                //     cout<<"\n";
                // }
            };
            Matrix operator+(const Matrix &a); 
            Matrix operator+(); 
            Matrix operator-(const Matrix &a);
            Matrix operator-();
            Matrix& operator+=(const Matrix &a);
            Matrix& operator-=(const Matrix &a);

            bool operator>(const Matrix &a);
            bool operator>=(const Matrix &a);
            bool operator<(const Matrix &a);
            bool operator<=(const Matrix &a);
            bool operator==(const Matrix &a);
            bool operator!=(const Matrix &a);
            
            Matrix& operator++();
            Matrix operator++(int);
            Matrix& operator--();
            Matrix operator--(int);
            
            Matrix operator*(const Matrix &a);
            Matrix& operator*=(const Matrix &a);
            Matrix& operator*=(const int other);
            friend Matrix operator*(const Matrix &a,const int other);
            friend Matrix operator*(const int other,const Matrix &a);
            friend ostream& operator<<(ostream& out,const Matrix&a);
            friend istream& operator>>(istream& in,const Matrix&a);
    };
}