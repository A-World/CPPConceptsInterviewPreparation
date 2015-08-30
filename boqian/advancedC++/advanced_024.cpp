/*
    Introduction to C++	:
    Video       :   Advanced C++ Define Implicit Type Conversion

    Category C Example : Rational class : Illustrating desing principle explained in example advaced_022.cpp
*/

#include <iostream>
#include <string>
using namespace std;

class Rational
{
    public :
        Rational(int n = 0, int d = 1 ) : num(n),den (d) {}
        int num, den;

//          const Rational operator * (const Rational &rhs)
//          {
//              return Rational (num * rhs.num, den * rhs.den);
//          }

        // Introducing following conversion, creates ambiguity with Rational r2 = r1 * 2; statement, so
        // method 2 conversion is not recommened.
        // operator int () const {return num / den ; }
};

// Define a non-member operator * on two rationals.

Rational operator * (Rational lhs, Rational rhs)
{
    return Rational(lhs.num * rhs.num, lhs.den * rhs.den) ;
}

int main()
{
    Rational r1 = 23;
    Rational r2 = r1 * 2;
    Rational r3 = 3 * r1;

    return 0;
}