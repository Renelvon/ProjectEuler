#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    const unsigned int max = 10000;
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

    cout << "The requested arithmetic sequence made from three 4-digit primes is:" << endl;

    unsigned int d, n1, n2, n3;
    unsigned int digits[5], digits1[5], digits2[5];
    for (unsigned int i = 1001; i < 10000; ++i) {
        if (prime[i]) {
            n1 = i;
            d = 0;
            do {
                digits[d] = n1 % 10;
                n1 /= 10;
                ++d;
            } while (n1 > 0);

            reverse(digits, digits + d);
            while (next_permutation(digits, digits + 4)) {
                n2 = 0;
                for (unsigned int j = 0; j < d; ++j) {
                    n2 = n2 * 10 + digits[j];
                }
                    
                n3 = 2 * n2 - i;
                if (prime[n2] && n3 < max && prime[n3]) {
                    d = 0;
                    do {
                        digits2[d] = n3 % 10;
                        n3 /= 10;
                        ++d;
                    } while (n3 > 0);
                    sort(digits2, digits2 + 4);
                    copy(digits, digits + 4, digits1);
                    sort(digits1, digits1 + 4);
                    
                    if (i != 1487 && equal(digits1, digits1 + 4, digits2)) {
                        cout << i << " " << n2 << " " << 2 * n2 - i
                             << "\nand the concatenated number: "
                             << i << n2 << 2 * n2 - i << endl;
                    }
                }
            }
        }
    }
}
