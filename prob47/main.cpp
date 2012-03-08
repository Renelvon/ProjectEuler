#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    const unsigned int intmax = 1000000;
    const unsigned int primes = 4;

    // primediv[i]: Number of prime divisors of i.
    int *primediv = new int[intmax];
    fill(primediv, primediv + intmax, 0);
    for (unsigned int i = 2; i < intmax / 2; ++i) {
        if (0 == primediv[i]) {
            for (unsigned int j = 2 * i; j < intmax; j += i) {
                ++primediv[j];
            }
        }
    }

    int *pos = search_n(primediv + 2, primediv + intmax, primes, primes);
    unsigned int num = distance(primediv, pos);

    cout << "The first number of the first " << primes
         << " consecutive integers to have"
         << "\n" << primes << " distinct prime factors is: "
         << num << endl;

    delete[] primediv;
}
