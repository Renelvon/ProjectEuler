#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 700000000;
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(max));

    bool *prime = new bool [max];
    fill(prime, prime + max, true);
    prime[0] = false;
    prime[1] = false;
    for (unsigned int i = 4; i < max; i += 2) {
         prime[i] = false;
    }
    for (unsigned int i = 3; i < sqmax + 1; i += 2) {
        if (prime[i]) {
            for (unsigned int j = i * i; j < max; j += 2*i) {
                prime[j] = false;
            }
        }
    }

    const double percent = 0.10;
    /* South-east sequence: a_n = (2 * n + 1) * (2 * n + 1)
     * South-west sequence: b_n = a_n - 2 * n
     * North-west sequence: c_n = a_n - 4 * n
     * North-east sequence: d_n = a_n - 6 * n
     * where a_0 = b_0 = c_0 = d_0 = 1.
     */
    unsigned int n = 1, a = 9, b = 7, c = 5, d = 3, sumpn = 3;
    while (sumpn >= percent * (4 * n + 1)) {
        ++n;
        a = (2 * n + 1) * (2 * n + 1);
        b = a - 2 * n;
        c = a - 4 * n;
        d = a - 6 * n;
        if (prime[a]) {
            ++sumpn;
        }
        if (prime[b]) {
            ++sumpn;
        }
        if (prime[c]) {
            ++sumpn;
        }
        if (prime[d]) {
            ++sumpn;
        }
    }

    cout << "The side length of the square spiral for which"
         << "\nthe ratio of primes along both diagonals"
         << "\nfirst falls below " << 100 * percent << "% is: "
         << 2 * n + 1 << endl;

    delete [] prime;
}
