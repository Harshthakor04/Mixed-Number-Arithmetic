#include <iostream>
#include "mixed.h"
using namespace std;

int main()
{
    cout << "=== Mixed Class Constructor Tests ===" << endl;

    Mixed m1(2, 8, 12);   //improper fraction: should become 2 2/3
    cout << "Test 1: 2 8/12 → " << m1 << endl;

    Mixed m2(-4, 7, -3);  //negative denominator: sign fix and normalization
    cout << "Test 2: -4 7/-3 → " << m2 << endl;

    Mixed m3(0, -5, 3);   //negative numerator when integer is 0
    cout << "Test 3: 0 -5/3 → " << m3 << endl;

    Mixed m4(2, -1, 3);   //invalid: negative numerator with integer ≠ 0
    cout << "Test 4: 2 -1/3 → " << m4 << endl;

    Mixed m5(3, 6, 3);    //improper fraction: should become 5
    cout << "Test 5: 3 6/3 → " << m5 << endl;

    Mixed m6(0, 4, 2);    //improper fraction with zero integer part
    cout << "Test 6: 0 4/2 → " << m6 << endl;

    Mixed m7(0, 0, 5);    //zero fraction: should become 0
    cout << "Test 7: 0 0/5 → " << m7 << endl;

    Mixed m8(1, 2, 0);    //denominator zero: should become 0
    cout << "Test 8: 1 2/0 → " << m8 << endl;

    return 0;
}
