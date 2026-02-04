#include <iostream> 
using namespace std;

//class
class Mixed
{
    public:
        //contructors
        Mixed(int i, int n, int d);
        Mixed(int i = 0);
        
        //member functions
        double Evaluate() const;
        void ToFraction();
        void Simplify();

        //friend functions for output and input
        friend ostream& operator<<(ostream& a, const Mixed& b);
        friend istream& operator>>(istream& a, Mixed& b);

        //friend functions for arthemictic operators
        friend Mixed operator+(const Mixed& a, const Mixed& b);
        friend Mixed operator-(const Mixed& a, const Mixed& b);
        friend Mixed operator*(const Mixed& a, const Mixed& b);
        friend Mixed operator/(const Mixed& a, const Mixed& b);

        //friend functions for comparing operators
        friend bool operator<(const Mixed& a, const Mixed& b);
        friend bool operator>(const Mixed& a, const Mixed& b);
        friend bool operator<=(const Mixed& a, const Mixed& b);
        friend bool operator>=(const Mixed& a, const Mixed& b);
        friend bool operator==(const Mixed& a, const Mixed& b);
        friend bool operator!=(const Mixed& a, const Mixed& b);

    private:
        //data members
        int integer;
        int numerator;
        int denominator;

};