#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const unsigned int intmax = 1000000;

    unsigned int max2p = 0, d2 = 1;
    while (d2 <= intmax) {
        ++max2p;
        d2 *= 2;
    }

    unsigned int max10p = 0, d10 = 1;
    while (d10 <= intmax) {
        ++max10p;
        d10 *= 10;
    }

    unsigned int *digits2 = new unsigned int[max2p + 1];
    unsigned int *digits10 = new unsigned int[max10p + 1];
    
    fill(digits2, digits2 + max2p + 1, 0);
    fill(digits10, digits10 + max10p + 1, 0);
    digits2[0] = 1;

    unsigned int sump = 0;
    unsigned int num = 1, numtemp, d2half = 0, offset = 1;
    bool flag;
    for (num = 1; num < intmax; ) {
        numtemp = num;
        d10 = 0;
        do {
            digits10[d10] = numtemp % 10;
            numtemp /= 10;
            ++d10;
        } while (numtemp > 0);

        flag = true;
        for (unsigned int i = 0, j = d10 - 1; flag && i < j; ++i, --j) {
            flag = digits10[i] == digits10[j];
        }
        if (flag) {
            sump += num;
        }

        for (unsigned int i = d2half; ; --i) {
            if (0 == i) {
                fill(digits2 + 1, digits2 + max2p + 1, 0);
                if (0 == offset) {
                    ++d2half;
                }
                offset = 1 - offset;
                break;
            }
            if (0 == digits2[i]) {
                digits2[i] = 1;
                break;
            }
            digits2[i] = 0;
        }
        d2 = 2 * d2half + 2 - offset;
        reverse_copy(digits2, digits2 + d2half + 1 - offset,
                     digits2 + d2half + 1);

        num = 0;
        for (unsigned int i = 0; i < d2; ++i) {
            num = num * 2 + digits2[i];
        }
    }

    cout << "The sum of all numbers less than " << intmax
         << "\nwhich are palindromic in base in base 2 and base 10 is: "
         << sump << endl;

    delete[] digits2;
    delete[] digits10;
}
