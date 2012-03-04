#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const unsigned int intmax = 100000, target = 500;

    unsigned int num, divisors[intmax];
    divisors[0] = 0;
    fill(divisors + 1, divisors + intmax, 1);
    for (unsigned int i = 2; i < intmax; ++i) {
        num = i;
        while (num < intmax) {
            ++divisors[num];
            num += i;
        }
    }
    
    unsigned int d1 = 0, d2 = 0, maxn;
    for (unsigned int i = 0; i < intmax - 1; ++i) {
        if (divisors[i] * divisors[i + 1] > target) {
            if (0 == i % 2) {
                d1 = i;
                d2 = i + 1;
            } else {
                d1 = i + 1;
                d2 = i;
            }
            
            maxn = 1;
            while (0 == d1 % (1 << maxn)) {
                ++maxn;
            }
            --maxn;

            if (divisors[d1] / (maxn + 1) * maxn * divisors[d2] > target) {
                break;
            }
        }
    }

    cout << "The first triangle number to have over " << target
         << " proper divisors is: " << d1 * d2 / 2 << endl;
}
