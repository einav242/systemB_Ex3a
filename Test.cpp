#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

#include <string>
using namespace std;

TEST_CASE("Good input")
{
  //Initializing matrixs
  vector<double> v1 = {1, 2, 3, 4};
  vector<double> v2 = {10, 4, 4, 8, 7, 5, 5, 3, 0, -1, 2, -2, 4, 3, -8};
  vector<double> v3 = {0, 0, 0, 0};
  vector<double> v4 = {1};
  vector<double> v5 = {5, 6, 7, 8, 9, 5, 4, 22, 0, 3, -4, -8, -9, -2, 0};
  vector<double> v6 = {1, 5, -8, 9};
  vector<double> v7 = {8};
  Matrix m1{v1, 2, 2};
  Matrix equal_m1{v1, 2, 2};
  Matrix m2{v2, 3, 5};
  Matrix equal_m2{v2, 3, 5};
  Matrix m3{v3, 2, 2};
  Matrix equal_m3{v3, 2, 2};
  Matrix m4{v4, 1, 1};
  Matrix equal_m4{v4, 1, 1};
  Matrix m5{v5, 5, 3};
  Matrix equal_m5{v5, 5, 3};
  Matrix m6{v6, 2, 2};
  Matrix equal_m6{v6, 2, 2};
  Matrix m7{v7, 1, 1};
  Matrix equal_m7{v7, 1, 1};

  //Initializing matrixs for ++
  vector<double> plus1_v1 = {2, 3, 4, 5};
  vector<double> plus1_v2 = {11, 5, 5, 9, 8, 6, 6, 4, 1, 0, 3, -1, 5, 4, -7};
  vector<double> plus1_v3 = {1, 1, 1, 1};
  vector<double> plus1_v4 = {2};
  vector<double> plus1_v5 = {6, 7, 8, 9, 10, 6, 5, 23, 1, 4, -3, -7, -8, -1, 1};
  vector<double> plus1_v6 = {2, 6, -7, 10};
  Matrix plus1_m1{plus1_v1, 2, 2};
  Matrix plus1_m2{plus1_v2, 3, 5};
  Matrix plus1_m3{plus1_v3, 2, 2};
  Matrix plus1_m4{plus1_v4, 1, 1};
  Matrix plus1_m5{plus1_v5, 5, 3};
  Matrix plus1_m6{plus1_v6, 2, 2};
  
  //Initializing arrays --
  vector<double> minus1_v1 = {0, 1, 2, 3};
  vector<double> minus1_v2 = {9, 3, 3, 7, 6, 4, 4, 2, -1, -2, 1, -3, 3, 2, -9};
  vector<double> minus1_v3 = {-1, -1, -1, -1};
  vector<double> minus1_v4 = {0};
  vector<double> minus1_v5 = {4, 5, 6, 7, 8, 4, 3, 21, -1, 2, -5, -9, -10, -3, -1};
  vector<double> minus1_v6 =  {0, 4, -9, 8};
  Matrix minus1_m1{minus1_v1, 2, 2};
  Matrix minus1_m2{minus1_v2, 3, 5};
  Matrix minus1_m3{minus1_v3, 2, 2};
  Matrix minus1_m4{minus1_v4, 1, 1};
  Matrix minus1_m5{minus1_v5, 5, 3};
  Matrix minus1_m6{minus1_v6, 2, 2};
  
  //check operator '=='
  CHECK((m1 == equal_m1) == true);
  CHECK((m2 == equal_m2) == true);
  CHECK((m3 == equal_m3) == true);
  CHECK((m4 == equal_m4) == true);
  CHECK((m5 == equal_m5) == true);
  CHECK((m6 == equal_m6) == true);
  CHECK((m7 == equal_m7) == true);

  CHECK((m1 == m3) == false);
  CHECK((m1 == m6) == false);
  CHECK((m3 == m6) == false);
  CHECK((m7 == m4) == false);

  //check operator '!='
  CHECK((m1 != m3) == true);
  CHECK((m1 != m6) == true);
  CHECK((m3 != m6) == true);
  CHECK((m4 != m7) == true);

  CHECK((m1 != equal_m1) == false);
  CHECK((m2 != equal_m2) == false);
  CHECK((m3 != equal_m3) == false);
  CHECK((m4 != equal_m4) == false);
  CHECK((m5 != equal_m5) == false);
  CHECK((m6 != equal_m6) == false);
  CHECK((m7 != equal_m7) == false);

  //check operator '+'
  CHECK(((m1 + m3) == m1));
  vector<double> v_ans1 = {2, 7, -5, 13};
  Matrix m_ans1{v_ans1, 2, 2};
  CHECK(((m1 + m6) == m_ans1));
  vector<double> v_ans8 = {2, 4, 6, 8};
  Matrix m_ans8{v_ans8, 2, 2};
  CHECK(((m1 + m1) == m_ans8));
  CHECK(((m3 + m3) == m3));
  CHECK(((m6+m3)==m6));
  vector<double> v_ans9 = {2, 10, -16, 18};
  Matrix m_ans9{v_ans9, 2, 2};
  CHECK(((m6 + m6) == m_ans9));

  //check operator '-'
  CHECK(((m1-m1)==m3));
  vector<double> v_ans3 = {0, -3, 11, -5};
  Matrix m_ans3{v_ans3, 2, 2};
  CHECK(((m1 - m6) == m_ans3));
  CHECK(((m1-m3)==m1));
  vector<double> v_ans10 = {-1, -2, -3, -4};
  Matrix m_ans10{v_ans10, 2, 2};
  CHECK(((m3-m1)==m_ans10));
  CHECK(((m3-m3)==m3));
  vector<double> v_ans11 = {-1, -5, 8, -9};
  Matrix m_ans11{v_ans11, 2, 2};
  CHECK(((m3-m6)==m_ans11));
  vector<double> v_ans12 = {0, 3, -11, 5};
  Matrix m_ans12{v_ans12, 2, 2};
  CHECK(((m6-m1)==m_ans12));
  CHECK(((m6-m3)==m6));
  CHECK(((m6-m6)==m3));

  //check operator '+'
  CHECK(((+m1) == m1));
  CHECK(((+m2) == m2));
  CHECK(((+m3) == m3));
  CHECK(((+m4) == m4));
  CHECK(((+m5) == m5));
  CHECK(((+m6) == m6));

  //check operator '-'
  vector<double> v_ans2 = {-1, -2, -3, -4};
  Matrix m_ans2{v_ans2, 2, 2};
  CHECK(((-m1) == m_ans2));

  vector<double> v_ans4 = {-10, -4, -4, -8, -7, -5, -5, -3, 0, 1, -2, 2, -4, -3, 8};
  Matrix m_ans4{v_ans4, 3, 5};
  CHECK(((-m2) == m_ans4));

  CHECK(((-m3) == m3));

  vector<double> v_ans5 = {-1};
  Matrix m_ans5{v_ans5, 1, 1};
  CHECK(((-m4) == m_ans5));

  vector<double> v_ans6 = {-5, -6, -7, -8, -9, -5, -4, -22, 0, -3, 4, 8, 9, 2, 0};
  Matrix m_ans6{v_ans6, 5, 3};
  CHECK(((-m5) == m_ans6));

  vector<double> v_ans7 = {-1, -5, 8, -9};
  Matrix m_ans7{v_ans7, 2, 2};
  CHECK(((-m6) == m_ans7));


  //check operator '+=' and '-='
  m1 += m6;
  CHECK((m1 == m_ans1));
  m1 -= m3;
  CHECK((m1 == m_ans1));
  m1+=m3;
  CHECK((m1 == m_ans1));
  
  m1-=m6;
  CHECK((m1==equal_m1));
  m6+=m1;
  CHECK((m6 == m_ans1));
  m6 -= m3;
  CHECK((m6 == m_ans1));
  m6-=m1;
  CHECK((m6==equal_m6));
  
  m3+=m1;
  CHECK((m3==equal_m1));
  m3+=m6;
  CHECK((m3==m_ans1));
  m3-=m6;
  CHECK((m3==equal_m1));
  m3-=m1;
  CHECK((m3==equal_m3));


  //check operator '>=','<=','<','>'
  CHECK(((m1 >= m1) == true)); //8>=8

  CHECK(((m1 > m3) == true)); //2+7-5+13=8>0

  CHECK(((m1 > m6) == true)); //8>7

  CHECK(((m4 < m7)) == true); //1<8

  CHECK(((m4 <= m7)) == true);
  
  CHECK((m3 < m6) == true); //0<7

  CHECK((m3 > m6) == false);
  
  CHECK((m3 >= m6) == false);


  //check operator '++'
  m1++;
  m2++;
  m3++;
  m4++;
  m5++;
  m6++;
  CHECK((m1==plus1_m1));
  CHECK((m2==plus1_m2));
  CHECK((m3==plus1_m3));
  CHECK((m4==plus1_m4));
  CHECK((m5==plus1_m5));
  CHECK((m6==plus1_m6));
  //Initializing matrixs
  m1--;
  m2--;
  m3--;
  m4--;
  m5--;
  m6--;
  CHECK((m1==equal_m1));
  CHECK((m2==equal_m2));
  CHECK((m3==equal_m3));
  CHECK((m4==equal_m4));
  CHECK((m5==equal_m5));
  CHECK((m6==equal_m6));
  //check operator '--'
  m1--;
  m2--;
  m3--;
  m4--;
  m5--;
  m6--;
  CHECK((m1==minus1_m1));
  CHECK((m2==minus1_m2));
  CHECK((m3==minus1_m3));
  CHECK((m4==minus1_m4));
  CHECK((m5==minus1_m5));
  CHECK((m6==minus1_m6));
  //Initializing matrixs
  m1++;
  m2++;
  m3++;
  m4++;
  m5++;
  m6++;
  CHECK((m1==equal_m1));
  CHECK((m2==equal_m2));
  CHECK((m3==equal_m3));
  CHECK((m4==equal_m4));
  CHECK((m5==equal_m5));
  CHECK((m6==equal_m6));

  //check operator '*','*='= sqalr
  vector<double> v_ans13 = {3, 6, 9, 12};
  Matrix m_ans13{v_ans13, 2, 2};
  CHECK(((3*m1) == m_ans13));
  CHECK(((m1*3) == m_ans13));
  m1*=3;
  CHECK((m1==m_ans13));
  vector<double> v_ans14 = {50, 20, 20, 40, 35, 25, 25, 15, 0, -5, 10, -10, 20, 15, -40};
  Matrix m_ans14{v_ans14, 3, 5};
  CHECK(((5*m2) == m_ans14));
  CHECK(((m2*5) == m_ans14));
  m2*=5;
  CHECK((m2==m_ans14));
  vector<double> v_ans15 = {0,0,0,0};
  Matrix m_ans15{v_ans15, 2, 2};
  CHECK(((8*m3) == m_ans15));
  CHECK(((m3*8) == m_ans15));
  m3*=9;
  CHECK((m3==m_ans15));
  vector<double> v_ans16 = {9};
  Matrix m_ans16{v_ans16, 1, 1};
  CHECK(((9*m4) == m_ans16));
  CHECK(((m4*9) == m_ans16));
  m4*=9;
  CHECK((m4==m_ans16));
  vector<double> v_ans17 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Matrix m_ans17{v_ans17, 5, 3};
  CHECK(((0*m5) == m_ans17));
  CHECK(((m5*0) == m_ans17));
  m5*=0;
  CHECK((m5==m_ans17));
  vector<double> v_ans18 = {10, 50, -80, 90};
  Matrix m_ans18{v_ans18, 2, 2};
  CHECK(((10*m6) == m_ans18));
  CHECK(((m6*10) == m_ans18));
  m6*=10;
  CHECK((m6==m_ans18));

  //check operator '*' mateix
  vector<double> v_ans19 = {0, 0, 0, 0};
  Matrix m_ans19{v_ans19, 2, 2};
  CHECK(((equal_m1*equal_m3) == m_ans19));
  CHECK(((equal_m3*equal_m1) == m_ans19));
  vector<double> v_ans20 = {-15, 23, -29, 51};
  Matrix m_ans20{v_ans20, 2, 2};
  CHECK(((equal_m1*equal_m6) == m_ans20));
  vector<double> v_ans21 = {16, 22, 19, 20};
  Matrix m_ans21{v_ans21, 2, 2};
  CHECK(((equal_m6*equal_m1) == m_ans21));
  vector<double> v_ans22 = {7,10,15,22};
  Matrix m_ans22{v_ans22, 2, 2};
  CHECK(((equal_m1*equal_m1) == m_ans22));
  vector<double> v_ans23 = {0,0,0,0};
  Matrix m_ans23{v_ans23, 2, 2};
  CHECK(((equal_m3*equal_m6) == m_ans23));
  CHECK(((equal_m6*equal_m3) == m_ans23));
  CHECK(((equal_m3*equal_m3) == m_ans23));
  vector<double> v_ans24 = {-39,50,-80,41};
  Matrix m_ans24{v_ans24, 2, 2};
  CHECK(((equal_m6*equal_m6) == m_ans24));
  vector<double> v_ans25 = {59,138,26,86,143,60,91,86,-20};
  Matrix m_ans25{v_ans25, 3, 3};
  CHECK(((equal_m2*equal_m5) == m_ans25));

  //check operator '*=' mateix
  equal_m1*=equal_m6;
  CHECK((equal_m1 == m_ans20));
  equal_m3*=equal_m6;
  CHECK((equal_m3 == m_ans19));
  equal_m6*=equal_m6;
  CHECK((equal_m6 == m_ans24));
  equal_m6*=equal_m3;
  CHECK((equal_m6 == m_ans19));
  equal_m2*=equal_m5;
  CHECK((equal_m2 == m_ans25));
}

TEST_CASE("Bad use of operators")
{
  //Initializing matrixs
  vector<double> v1 = {1, 2, 3, 4};
  vector<double> v2 = {10, 4, 4, 8, 7, 5, 5, 3, 0, -1, 2, -2, 4, 3, -8};
  vector<double> v3 = {0, 0, 0, 0};
  vector<double> v4 = {1};
  vector<double> v5 = {5, 6, 7, 8, 9, 5, 4, 22, 0, 3, -4, -8, -9, -2, 0};
  vector<double> v6 = {1, 5, -8, 9};
  Matrix m1{v1, 2, 2};
  Matrix m2{v2, 3, 5};
  Matrix m3{v3, 2, 2};
  Matrix m4{v4, 1, 1};
  Matrix m5{v5, 5, 3};
  Matrix m6{v6, 2, 2};

  //attempt to add matrices not of the same size
  CHECK_THROWS(m1+m2);
  CHECK_THROWS(m2+m3);
  CHECK_THROWS(m3+m4);
  CHECK_THROWS(m4+m5);
  CHECK_THROWS(m5+m6);
  CHECK_THROWS(m1+m4);
  CHECK_THROWS(m2+m4);
  CHECK_THROWS(m3+m5);
  CHECK_THROWS(m4+m6);
  CHECK_THROWS(m5+m1);

  CHECK_THROWS(m1+=m2);
  CHECK_THROWS(m2+=m3);
  CHECK_THROWS(m3+=m4);
  CHECK_THROWS(m4+=m5);
  CHECK_THROWS(m5+=m6);
  CHECK_THROWS(m1+=m4);
  CHECK_THROWS(m2+=m4);
  CHECK_THROWS(m3+=m5);
  CHECK_THROWS(m4+=m6);
  CHECK_THROWS(m5+=m1);
  //attempt to sub matrices not of the same size
  CHECK_THROWS(m1-m2);
  CHECK_THROWS(m2-m3);
  CHECK_THROWS(m3-m4);
  CHECK_THROWS(m4-m5);
  CHECK_THROWS(m5-m6);
  CHECK_THROWS(m1-m4);
  CHECK_THROWS(m2-m4);
  CHECK_THROWS(m3-m5);
  CHECK_THROWS(m4-m6);
  CHECK_THROWS(m5-m1);

  CHECK_THROWS(m1-=m2);
  CHECK_THROWS(m2-=m3);
  CHECK_THROWS(m3-=m4);
  CHECK_THROWS(m4-=m5);
  CHECK_THROWS(m5-=m6);
  CHECK_THROWS(m1-=m4);
  CHECK_THROWS(m2-=m4);
  CHECK_THROWS(m3-=m5);
  CHECK_THROWS(m4-=m6);
  CHECK_THROWS(m5-=m1);

  //attempt to compare matrices that are not the same size
  CHECK_THROWS((m1.operator>(m2)));
  CHECK_THROWS((m2.operator<(m3)));
  CHECK_THROWS((m3.operator==(m4)));
  CHECK_THROWS((m4.operator!=(m5)));
  CHECK_THROWS((m5.operator>=(m6)));
  CHECK_THROWS((m1.operator<=(m4)));
  CHECK_THROWS((m2.operator!=(m4)));
  CHECK_THROWS((m3.operator==(m5)));
  CHECK_THROWS((m4.operator<(m6)));
  CHECK_THROWS((m5.operator<=(m1)));

  //attempt to multiplication matrices that row not equal to the colum
  CHECK_THROWS(m1*m2);
  CHECK_THROWS(m2*m1);
  CHECK_THROWS(m1*m4);
  CHECK_THROWS(m1*m5);
  CHECK_THROWS(m4*m1);
  CHECK_THROWS(m5*m1);
  CHECK_THROWS(m2*m3);
  CHECK_THROWS(m3*m2);
  CHECK_THROWS(m2*m4);
  CHECK_THROWS(m4*m2);
  CHECK_THROWS(m2*m6);
  CHECK_THROWS(m6*m2);
  CHECK_THROWS(m3*m4);
  CHECK_THROWS(m4*m3);
  CHECK_THROWS(m3*m5);
  CHECK_THROWS(m5*m3);
  CHECK_THROWS(m4*m5);
  CHECK_THROWS(m5*m4);
  CHECK_THROWS(m4*m6);
  CHECK_THROWS(m6*m4);
  CHECK_THROWS(m5*m6);
  CHECK_THROWS(m6*m5);
}