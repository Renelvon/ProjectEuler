#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    /* The nth power of 10 has n + 1 digits, so we needn't search
     * beyond powers of numbers 1 to 9.
     * Also, 9^{22} < 10^{21}, so we needn't search beyond powers of order 21.
     */
    unsigned int n;
    double frac;
    unsigned int count = 1; // There is exactly one nth power of 1 that is n-digit.
    for (unsigned int i = 2; i < 10; ++i) {
        frac = 10 / static_cast<double>(i);
        n = 0;
        while (pow(frac, n + 1) <= 10) {
            ++n;
        }
        count += n;
    }

    cout << "There are " << count << " n-digit positive integers"
         << " which are also an nth power." << endl;
}
