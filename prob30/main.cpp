#include <iostream>

using namespace std;

int main() {
    unsigned int powers[10];
    powers[0] = 0;
    powers[1] = 1;
    for (unsigned int i = 2, p; i < 10; ++i) {
        p = 1;
        for (unsigned int j = 0; j < 5; ++j) {
            p *= i;
        }
        powers[i] = p;
    }

    /* 7 * pow(9, 5) = 413343 < 1000000
     * so there cannot be a number with 7 digits
     * whose digits raised to the 5th power sum to itself.
     * Furthermore, 6 * pow(9, 5) = 354294 is the maximum possible sum.
     */
    const unsigned int intmax = 354294;
    unsigned int totalsum = 0, d, num, sum5;
    unsigned int digits[8];
    for (unsigned int i = 10; i < intmax; ++i) {
        num = i;
        d = 0;
        do {
            digits[d] = num % 10;
            num /= 10;
            ++d;
        } while (num > 0);

        sum5 = 0;
        for (unsigned int j = 0; j < d; ++j) {
            sum5 += powers[digits[j]];
        }
        if (i == sum5) {
            totalsum += i;
        }
    }

    cout << "The sum of all the numbers that can be written"
         << "\nas the sum of fifth powers of their digits is: "
         << totalsum << endl;
}
