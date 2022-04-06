
#include <string>
#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <iterator>
using namespace std;

double sum(zich::Matrix m)
{
    const unsigned int r = m.row;
    const unsigned int c = m.colum;
    double sum=0;
    for (unsigned int i = 0; i < r; i++)
    {
        for (unsigned int j = 0; j < c; j++)
        {
          sum+=m.v[i][j];
        }
    }
    return sum;
}

namespace zich
{
    Matrix Matrix::operator+(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = this->v[i][j] + a.v[i][j];
                k++;
            }
        }
        Matrix sum{ans, int(r), int(c)};
        return sum;
    }

    Matrix Matrix::operator+()
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = this->v[i][j];
                k++;
            }
        }
        Matrix result{ans, int(r), int(c)};
        return result;
    }

    Matrix Matrix::operator-(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = this->v[i][j] - a.v[i][j];
                k++;
            }
        }
        Matrix sub{ans, int(r), int(c)};
        return sub;
    }

    Matrix Matrix::operator-()
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                if (this->v[i][j] != 0)
                {
                    ans[k] = this->v[i][j] * (-1);
                }
                else
                {
                    ans[k] = 0;
                }
                k++;
            }
        }
        Matrix result{ans, int(r), int(c)};
        return result;
    }

    Matrix& Matrix::operator+=(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] += a.v[i][j];
            }
        }
        return *this;
    }

    Matrix &Matrix::operator-=(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] -= a.v[i][j];
            }
        }
        return *this;
    }

    
    bool Matrix::operator==(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for(unsigned int i=0;i<r;i++)
        {
            for(unsigned int j=0;j<c;j++)
            {
                if(a.v[i][j]!=this->v[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool Matrix::operator>(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        double sum1=sum(*this);
        double sum2=sum(a);
        return(sum1>sum2);
    }
    
    bool Matrix::operator>=(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        return(this->operator>(a) || this->operator==(a));
    }
    
    bool Matrix::operator<(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        double sum1=sum(*this);
        double sum2=sum(a);
        return sum1<sum2;
    }
    
    bool Matrix::operator<=(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        return(this->operator<(a) || this->operator==(a));
    }
    
    bool Matrix::operator!=(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        return !(*this==a);
    }

    
    Matrix& Matrix::operator++()
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j]=this->v[i][j]+1;
            }
        }
        return *this;
    }

    Matrix Matrix::operator++(int)
    {
        Matrix ans=+(*this);
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j]=this->v[i][j]+1;
            }
        }
        return ans;

    }
    
    Matrix &Matrix::operator--()
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j]--;
            }
        }
        return *this;
    }
    
    Matrix Matrix::operator--(int)
    {
        Matrix ans=+(*this);
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j]--;
            }
        }
        return ans;
    }


    Matrix operator*(const Matrix &a, const int other)
    {
        const unsigned int r = a.row;
        const unsigned int c = a.colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = a.v[i][j]*other;
                k++;
            }
        }
        Matrix mult{ans, int(r), int(c)};
        return mult;
    }
    
    Matrix operator*(const int other, const Matrix &a)
    {
        const unsigned int r = a.row;
        const unsigned int c = a.colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = a.v[i][j]*other;
                k++;
            }
        }
        Matrix mult{ans, int(r), int(c)};
        return mult;
    }
    
    Matrix &Matrix::operator*=(const int other)
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] *= other;
            }
        }
        return *this;
    }
    
        Matrix Matrix::operator*(const Matrix &a)
    {
        if (a.row != this->colum)
        {
            throw std::invalid_argument("The number of columns in the left matrix should be equal to the number of rows in the right matrix");
        }
        const unsigned int r = this->row;
        const unsigned int c = a.colum;
        vector<double> ans(r * c);
         for(unsigned int i=0;i<a.row;i++)
        {
            ans[i]=0;
        }
        Matrix mult{ans, int(r), int(c)};
        for(unsigned int i=0;i<this->row;i++)
        {
            for(unsigned int j=0;j<a.colum;j++)
            {
                for(unsigned int k=0;k<this->colum;k++)
                {
                    mult.v[i][j]+=this->v[i][k]*a.v[k][j];
                }
            }
        }
        return mult;
    }

    Matrix &Matrix::operator*=(const Matrix &a)
    {
        if (a.row != this->colum)
        {
            throw std::invalid_argument("The number of columns in the left matrix should be equal to the number of rows in the right matrix");
        }
       Matrix c=*this * a;
       *this=c;
        return *this;
    }
    
    ostream &operator<<(ostream &out, const Matrix &a)
    {
        return out;
    }
    
    istream &operator>>(istream &in, const Matrix &a)
    {
        return in;
    }
}