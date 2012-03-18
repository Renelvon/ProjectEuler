#include <algorithm>
#include <iostream>

using namespace std;

unsigned int *sigma;
int *chain;

int calc(unsigned int i, unsigned int start, unsigned int depth) {
    if (start == i) {
        return depth;
    }

    if (chain[i] >= 0 || chain[i] == -2) {
        chain[start] = 0;
        return -1;
    } else {
        chain[i] = -2;
    }

    int res = calc(sigma[i], start, depth + 1);
    if (res >= 0 || chain[i] == -2) {
        chain[i] = res;
    }
    return res;
}

int main() {
    const unsigned int intmax = 1000000;

    sigma = new unsigned int[intmax + 1];
    chain = new int[intmax + 1];
    sigma[0] = 0;
    sigma[1] = 0;
    fill(sigma + 2, sigma + intmax + 1, 1);
    chain[0] = 1;
    chain[1] = 0;
    fill(chain + 2, chain + intmax + 1, -1);
    for (unsigned int i = 2; i < intmax + 1; ++i) {
         for (unsigned int j = 2 * i; j < intmax + 1; j += i) {
             sigma[j] += i;
        }
        if (sigma[i] > intmax) {
            chain[i] = 0;
        } else if (i == sigma[i]) {
            chain[i] = 1;
        }
    }

    unsigned int besti = 0, bestc = 1;
    for (unsigned int i = 0; i < intmax; ++i) {
        if (-1 == chain[i]) {
            chain[i] = max(0, calc(sigma[i], i, 1));
        }
        
        if (chain[i] > static_cast<int>(bestc)) {
            bestc = chain[i];
            besti = i;
        }
    }

    cout << "The smallest member of the longest amicable chain"
         << "\nwith no element exceeding " << intmax << " is: "
         << besti << endl;

    delete[] chain;
    delete[] sigma;
}
