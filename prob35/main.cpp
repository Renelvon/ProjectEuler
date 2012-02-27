#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    const unsigned int max = 1000000; // Must be greater than 7
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(max));

    bool prime[max];
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

    // BUGGY
    bool flag;
    unsigned int digits[10];
    unsigned int d, num, ncirc = 4; // Code below does accept 2, 3, 5, 7.
    for (unsigned int i = 11; i < max; ++i) {
        if (prime[i]) {
            num = i;
            d = 0;
            flag = true;
            do {
                digits[d] = num % 10;
                num /= 10;
                flag = (0 != digits[d] % 2) && (5 != digits[d]);
                ++d;
            } while (flag && num > 0);

            for (unsigned int r = 0; flag && r < d; ++r) {
                num = 0;
                for (unsigned int j = d; j-- > 0; ) {
                    num = num * 10 + digits[j];
                }
                flag = prime[num];
                rotate(digits, digits + 1, digits + d);
            } 

            if (flag) {
                ++ncirc;
            } else {
                prime[num] = false;
            }
        }
    }

    cout << "The number of circular primes below " << max
         << " is: " << ncirc << endl;
}
