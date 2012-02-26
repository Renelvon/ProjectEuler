#include <iostream>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
    if (0 == a) {
        return b;
    }

    if (0 == b) {
        return a;
    }

    if (a < b) {
        return gcd(b % a, a);
    }

    return gcd(a % b, b);
}

int main() {
    unsigned int prodn = 1, prodd = 1, di1, di2, dj1, dj2;
    for (unsigned int i = 11; i < 100; ++i) {
        for (unsigned int j = i + 1; j < 100; ++j) {
            di1 = i % 10;
            di2 = i / 10;
            dj1 = j % 10;
            dj2 = j / 10;
            if (
                (di1 == dj1 && di1 != 0 && i * dj2 == j * di2) ||
                (di1 == dj2 && di1 != 0 && i * dj1 == j * di2) ||
                (di2 == dj1 && di2 != 0 && i * dj2 == j * di1) ||
                (di2 == dj2 && di2 != 0 && i * dj1 == j * di1)
               ) {
                prodn *= i;
                prodd *= j;
            }
        }
    }

    prodd /= gcd(prodn, prodd);

    cout << "The solution to problem 33 of ProjectEuler is: " << prodd << endl;
}
