#include <iostream>
#include <cmath>
#include "mixed.h"

using namespace std;

//mixed constructor for with parameter list
Mixed :: Mixed(int i, int n, int d)
{
    //storing
    integer = i;
    numerator = n;
    denominator = d;

    if(d == 0)              //when denominator cannot be 0
    {
        integer = 0;
        numerator = 0;
        denominator = 1;
    } 

    if(i != 0 && n < 0)     //when integer is not 0 and numerator is negative
    {
        integer = 0;
        numerator = 0;
        denominator = 1;
    }

    if(d < 0)               //when the denominator is negative
    {
        denominator = -denominator;     //making denominator positive
        numerator = -numerator;         //making numerator positive
    }

    //when the fraction is not proper
    if(numerator >= denominator || numerator <= -denominator)
    {
        int extraInteger;
        extraInteger = numerator / denominator; //stores in extraInteger
        integer += extraInteger;                //adds it to integer
        numerator = numerator % denominator;    // upadtes numerator
    }

    Simplify();     //for simplifing the fraction
}

//second contructor
Mixed :: Mixed(int i)
{
    integer = i;
    numerator = 0;
    denominator = 1;        //default
}

//Evaluate funtion
double Mixed :: Evaluate() const
{
    double changing = integer + (numerator * 1.0 / denominator);     //changing to double

    return changing;
}
    
//toFraction function
void Mixed :: ToFraction()
{
    numerator = integer * denominator + numerator;      //combining fraction and integer
    integer = 0;                                        //removing integer
}

//simplify function
void Mixed :: Simplify()
{
    if(numerator == 0)          //if statement when numberator is 0
    {
        denominator = 1;
        
        return;
    }

    int extraNumerator;
    if(numerator < 0)                   //for getting the absolute
        extraNumerator = - numerator;
    else
        extraNumerator = numerator;

    int extraDenominator = denominator;
    int divisor = 1;

    for(int i = 2; i <= extraNumerator && i <= extraDenominator; i ++)  //for getting the common denominator
    {
        if(extraNumerator % i == 0 && extraDenominator % i == 0)
            divisor = i;
    }

    numerator = numerator / divisor;        //diving by the common denominator
    denominator = denominator / divisor;    //divinding by the coomon denominator

    if(denominator < 0)         //if statement to make the denominator positive
    {
        denominator = -denominator;     //changing postive
        numerator = -numerator;         //changing postive
    }
}
        
//output operator
ostream& operator<<(ostream& a, const Mixed& b)
{
    if(b.integer == 0 && b.numerator == 0)  //for 0 value
        a << "0";
    else if(b.integer == 0)                 //when proper fraction
        a << b.numerator << "/" << b.denominator;
    else if(b.numerator == 0)               //when proper fraction
        a << b.integer;
    else                                    //when mixed numbers
        a << b.integer << " " << b.numerator << "/" << b.denominator;
    
    return a;
}

//input operator
istream& operator>>(istream& a, Mixed& b)
{
    char sign;
    int i, n, d;

    a >> i >> n >> sign >> d;       //the format it should be

    if(d == 0 || sign != '/')       //chincking for invalid 
    {
        b.integer = 0;
        b.numerator = 0;
        b.denominator = 1;
    }
    else if((i != 0 && n < 0) || (i == 0 && d < 0))     //checking for negative fractions
    {
        b.integer = 0;
        b.numerator = 0;
        b.denominator = 1;
    }
    else
    {
        b.integer = i;
        b.numerator = n;
        b.denominator = d;
    }

    b.Simplify();       //for simplifing 

    return a;           //returns a
}

//addition operator
Mixed operator+(const Mixed& a, const Mixed& b)
{
    Mixed answer; 

    //changing to improper fraction
    int num1 = a.integer * a.denominator + a.numerator;
    int den1 = a.denominator;

    //changing to improper fraction
    int num2 = b.integer * b.denominator + b.numerator;
    int den2 = b.denominator;

    //does adding with common denominator
    answer.numerator = num1 * den2 + num2 * den1;
    answer.denominator = den1 * den2;

    //changing to a mixed number
    answer.integer = answer.numerator / answer.denominator;
    answer.numerator = answer.numerator % answer.denominator;

    answer.Simplify();  //again for simplifing

    return answer;      //returns the answer
}

//subtracting operator
Mixed operator-(const Mixed& a, const Mixed& b)
{
    Mixed answer; 

    //changing to improper fraction
    int num1 = a.integer * a.denominator + a.numerator;
    int den1 = a.denominator;
    
    //changing to improper fraction
    int num2 = b.integer * b.denominator + b.numerator;
    int den2 = b.denominator;

    //suntracting with the common denominator
    answer.numerator = num1 * den2 - num2 * den1;
    answer.denominator = den1 * den2;

    //converting back to mixed numbers
    answer.integer = answer.numerator / answer.denominator;
    answer.numerator = answer.numerator % answer.denominator;

    answer.Simplify();  //simplifing again

    return answer;
}

//multiplication operator
Mixed operator*(const Mixed& a, const Mixed& b)
{
     Mixed answer; 

    //changing to improper fraction
    int num1 = a.integer * a.denominator + a.numerator;
    int den1 = a.denominator;

    //changing to improper fraction
    int num2 = b.integer * b.denominator + b.numerator;
    int den2 = b.denominator;

    //doing the multiplication for numerator and denominator
    answer.numerator = num1 * num2;
    answer.denominator = den1 * den2;

    //converting back to mixed numbers
    answer.integer = answer.numerator / answer.denominator;
    answer.numerator = answer.numerator % answer.denominator;

    answer.Simplify();  //simplifing again

    return answer;
}

//division operator
Mixed operator/(const Mixed& a, const Mixed& b)
{
    Mixed answer; 
    
    //changing to improper fraction
    int num1 = a.integer * a.denominator + a.numerator;
    int den1 = a.denominator;

    //changing to improper fraction
    int num2 = b.integer * b.denominator + b.numerator;
    int den2 = b.denominator;

    if (num2 == 0)      //if statemnt for checking 0
    {
        answer.integer = 0;
        answer.numerator = 0;
        answer.denominator = 1;
        return answer;
    }

    //multipling by the reciprocal
    answer.numerator = num1 * den2;
    answer.denominator = den1 * num2;

    if (answer.denominator < 0)     //if statement for checking the denominator is postive
    {
        answer.denominator = -answer.denominator;
        answer.numerator = -answer.numerator;
    }

    //converting to a mixed number
    answer.integer = answer.numerator / answer.denominator;
    answer.numerator = answer.numerator % answer.denominator;

    answer.Simplify();  //simplifing

    return answer;
}

//less than operator
bool operator<(const Mixed& a, const Mixed& b)
{
    //changing to improper fraction
    int num1 = a.integer * a.denominator + a.numerator;
    int den1 = a.denominator;

    //changing to improper fraction
    int num2 = b.integer * b.denominator + b.numerator;
    int den2 = b.denominator;

    return num1 * den2 < num2 * den1;       //does comparing and returns it
}

//greater than operator
bool operator>(const Mixed& a, const Mixed& b)
{
    return b < a;       //using the less than operator but reversing it
}

//less than equal to operator
bool operator<=(const Mixed& a, const Mixed& b)
{
    return !(a > b);    //using operator for not greater than less than or equal
}


bool operator>=(const Mixed& a, const Mixed& b)
{
    return !(a < b);    //using operator for not less greater or equal
}

//equal operator
bool operator==(const Mixed& a, const Mixed& b)
{
    //changing to improper fraction
    int num1 = a.integer * a.denominator + a.numerator;
    int den1 = a.denominator;

    //changing to improper fraction
    int num2 = b.integer * b.denominator + b.numerator;
    int den2 = b.denominator;

    return num1 * den2 == num2 * den1;  //checking eual during the multiplication
}

//not equal to operator
bool operator!=(const Mixed& a, const Mixed& b)
{
    return !(a == b);   //using the operator and checking when not equal
}