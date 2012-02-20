#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 2000000;
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(max)) + 1;
    unsigned long int sump = 0;

    bool prime[max];
    fill(prime, prime + max, true);
    prime[0] = false;
    prime[1] = false;
    for (unsigned int i = 4; i < max; i += 2) {
         prime[i] = false;
    }
    for (unsigned int i = 3; i < sqmax; i += 2) {
        if (prime[i]) {
            for (unsigned int j = i * i; j < max; j += 2*i) {
                prime[j] = false;
            }
        }
    }

    for (unsigned int i = 2; i < max; ++i) {
        if (prime[i]) {
            sump += i;
        }
    }

    cout << "The sum of all primes below " << max
         << " is: " << sump << endl;
}
