#include <iostream>
#include <cmath>    // For pow and sqrt functions
#include <numeric>  // For gcd function (C++17 and later)
using namespace std;

int main() {
    // Part (a): Calculate 2 raised to the power of 3
    double powerResult = pow(2, 3);
    cout << "2^3 = " << powerResult << endl;

    // Part (b): Find the square root of the result
    double sqrtResult = sqrt(powerResult);
    cout << "Square root of " << powerResult << " = " << sqrtResult << endl;

    // Part (c): Calculate GCD of sqrtResult and 18
    int gcdResult = gcd(static_cast<int>(sqrtResult), 18);
    cout << "GCD of " << sqrtResult << " and 18 = " << gcdResult << endl;

    return 0;
}
