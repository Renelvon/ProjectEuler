#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 10000000;
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(max)) + 1;

    bool* prime = new bool [max];
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

    unsigned int maxprime = 2143, n = 4, num;
    unsigned int intarr[7] = {1, 2, 3, 4, 5, 6, 7};
    // Note: 1234 is not prime and neither is 1234567
    while (next_permutation(intarr, intarr + 4)) {
        num = 0;
        for (unsigned int i = 4; i-- > 0; ) { 
            num = 10 * num + intarr[i];
        }
        if (num > maxprime && prime[num]) {
            maxprime = num;
        }
    }

    // Note: At this point, intarr[] = {1, 2, 3, 4, 5, 6, 7}
    while (next_permutation(intarr, intarr + 7)) {
        num = 0;
        for (unsigned int i = 7; i-- > 0; ) { 
            num = 10 * num + intarr[i];
        }
        if (num > maxprime && prime[num]) {
            maxprime = num;
            n = 7;
        }
    }

    cout << "The largest n-digit pandigital prime occurs for n = " << n
         << ": " << maxprime << endl;
    
    delete [] prime;
}
