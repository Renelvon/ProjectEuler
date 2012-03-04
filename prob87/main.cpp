#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool *isSum;

bool pred(unsigned int i) {
    return isSum[i];
}

int main() {
    const unsigned long int intmax = 50000000;
    const unsigned int maxp = static_cast<unsigned int>(sqrt(intmax)) + 1;
    const unsigned int sqmaxp = static_cast<unsigned int>(sqrt(maxp));

    bool *prime = new bool[maxp];
    fill(prime, prime + maxp, true);
    prime[0] = false;
    prime[1] = false;
    for (unsigned int i = 4; i < maxp; i += 2) {
         prime[i] = false;
    }
    for (unsigned int i = 3; i < sqmaxp + 1; i += 2) {
        if (prime[i]) {
            for (unsigned int j = i * i; j < maxp; j += 2*i) {
                prime[j] = false;
            }
        }
    }

    vector<unsigned long int> pow2, pow3, pow4;
    for (unsigned long int i = 2; i < maxp; ++i) {
        if (prime[i]) {
            pow2.push_back(i * i);
            if (i * i * i < intmax) {
                pow3.push_back(i * i * i);
                if (i * i * i * i < intmax) {
                    pow4.push_back(i * i * i * i);
                }
            }
        }
    }

    isSum = new bool[intmax];
    fill(isSum, isSum + intmax, false);
    for (unsigned int i = 0; i < pow2.size(); ++i) {
        for (unsigned int j = 0; j < pow3.size(); ++j) {
            for (unsigned int k = 0; k < pow4.size(); ++k) {
                if (pow2[i] + pow3[j] + pow4[k] < intmax) {
                    isSum[pow2[i] + pow3[j] + pow4[k]] = true;
                }
            }
        }
    }

    unsigned int countSum = 0;
    for (unsigned int i = 0; i < intmax; ++i) {
        if (isSum[i]) {
            ++countSum;
        }
    }

    cout << "There are " << countSum
         << " numbers below " << intmax << " which can be writen"
         << "\nas a sum of a prime square, prime cube, and prime fourth power."
         << endl;

    delete[] prime;
    delete[] isSum;
}
