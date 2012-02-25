#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    // NOTE: The value of max depends on the value of target.
    const unsigned int max = 80;
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

    const unsigned int target = 5000;
    /* ways[n][p] is the number of ways n can be written
     * as a sum of one or more prime numbers not exceeding p.
     */
    unsigned int ways[max + 1][max + 1], sum;
    fill(ways[0], ways[0] + max + 1, 0);
    fill(ways[1], ways[1] + max + 1, 0);
    for (unsigned int n = 2; n < max + 1; ++n) {
        ways[n][0] = 0;
        ways[n][1] = 0;
    }
    for (unsigned int n = 2; n < max + 1; ++n) {
        for (unsigned int p = 2; p < n; ++p) {
            sum = 0;
            for (unsigned int j = 2; j < p + 1; ++j) {
                sum += prime[j] ? ways[n - j][j] : 0;
            }
            ways[n][p] = sum;
        }
        ways[n][n] = ways[n][n - 1] + (prime[n] ? 1 : 0);
        fill(ways[n] + n, ways[n] + max + 1, ways[n][n]);
    }

    unsigned int maxi = 2;
    for (unsigned int n = 3; n < max + 1; ++n) {
        if (ways[n][max] - (prime[n] ? 1 : 0) >
            ways[maxi][max] - (prime[maxi] ? 1 : 0)) {
            maxi = n;
        }
        
        if (ways[maxi][max] - (prime[maxi] ? 1 : 0) > target) {
            break;
        }
    }

    cout << "The first value which can be written as a sum of prime numbers"
         << "\nin over " << target << " different ways is: "
         << (ways[maxi][max] > target ? maxi : (-1)) << endl;
}
