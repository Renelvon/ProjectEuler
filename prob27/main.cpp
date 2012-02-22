#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const int amax = 1000, bmax = 1000;
    const unsigned int nmax = bmax * (1 + amax + bmax);
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(nmax)) + 1;

    bool prime[nmax];
    fill(prime, prime + nmax, true);
    prime[0] = false;
    prime[1] = false;
    for (unsigned int i = 4; i < nmax; i += 2) {
         prime[i] = false;
    }
    for (unsigned int i = 3; i < sqmax; i += 2) {
        if (prime[i]) {
            for (unsigned int j = i * i; j < nmax; j += 2*i) {
                prime[j] = false;
            }
        }
    }

    int besta = 0, bestb = 0, bestn = 0;
    for (int b = 2, n; b < bmax; ++b) {
        if (prime[b]) {
            for (int a = -amax + 1; a < amax; ++a) {
                n = 0;
                while (prime[n * (n + a) + b]) {
                    ++n;
                }
                if (n > bestn) {
                    besta = a;
                    bestb = b;
                    bestn = n;
                }
            }
        }
    }

    cout << "The coefficients a and b (|a| < " << amax << ", |b| < " << bmax
         << ") for which the quadratic formula n * n + a * n + b\nproduces"
         << " the maximum number of primes for consecutive values of n,"
         << " starting with n = 0, are:\na = " << besta << ", b = " << bestb
         << "\nand their product is: " << besta * bestb << endl;
}
