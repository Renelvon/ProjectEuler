#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const unsigned int max = 1000000;
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(max)) + 1;

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

    const unsigned long int number = 600851475143;
    const unsigned int imax = static_cast<unsigned int>(sqrt(number));
    unsigned int maxp = 1;
    for (unsigned int i = 2; i < imax + 1; ++i) {
        if (prime[i] && (0 == number % i)) {
            maxp = i;
        }
    }

    cout << "The largest prime divisor of " << number
         << " is: " << maxp << endl;
}
