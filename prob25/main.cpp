#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const unsigned int numDigits = 1000;

    int f[3][numDigits + 1];
    for (unsigned int i = 0; i < 3; ++i) {
        fill(f[i], f[i] + numDigits + 1, -1);
    }
    f[0][0] = 0;
    f[1][0] = 1;
    
    unsigned int rep = 1;
    for (unsigned int i1 = 0, i2 = 1, i3 = 2, size = 0, remainder;
         size < numDigits;
         ++rep) {
        size = 0;
        remainder = 0;
        for (unsigned int sum; -1 != f[i2][size]; ++size) {
            f[i1][size] = max(0, f[i1][size]);
            sum = f[i1][size] + f[i2][size] + remainder;
            f[i3][size] = sum % 10;
            remainder = sum / 10;
        }

        if (0 != remainder) {
            f[i3][size++] = remainder;
        }

        i1 = (i1 + 1) % 3;
        i2 = (i2 + 1) % 3;
        i3 = (i3 + 1) % 3;
    }

    cout << "The first Fibonacci number to contain at least " << numDigits
         << " digits is the " << rep << "th term." << endl;
}
