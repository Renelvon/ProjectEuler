#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 1000000;
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

    bool flag;
    unsigned int digits[10];
    unsigned int d, num, sumtrunc = 0;
    for (unsigned int i = 11; i < max; ++i) {
        if (prime[i]) {
            // Decompose into digits by truncating from right to left.
            num = i;
            d = 0;
            flag = true;
            do {
                digits[d] = num % 10;
                num /= 10;
                if (num > 0) {
                    flag = prime[num];
                }
                ++d;
            } while (flag && num > 0);

            // Recompose number by constructing from left to right
            num = 0;
            for (unsigned int j = 0, p10 = 1; flag && j < d; ++j, p10 *= 10) {
                num += digits[j] * p10;
                flag = prime[num];
            }

            if (flag) {
                sumtrunc += i;
            }
        }
    }

    cout << "The sum of the only eleven primes that are both truncatable"
         << "\nfrom left to right and right to left is: " << sumtrunc << endl;
}
