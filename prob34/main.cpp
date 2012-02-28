#include <iostream>

using namespace std;

int main() {
    unsigned int factorials[10];
    factorials[0] = 1;
    for (unsigned int i = 1; i < 10; ++i) {
        factorials[i] = factorials[i - 1] * i;
    }

    /* 8 * 9! = 2903040 < 10000000
     * so there cannot be a number with 8 digits
     * whose digits' factorials sum to itself.
     * Furthermore, 7 * 9! = 2540160 is the maximum possible sum.
     */
    const unsigned int intmax = 2540160;
    unsigned int totalsum = 0, d, num, sumf;
    unsigned int digits[8];
    for (unsigned int i = 10; i < intmax; ++i) {
        num = i;
        d = 0;
        do {
            digits[d] = num % 10;
            num /= 10;
            ++d;
        } while (num > 0);

        sumf = 0;
        for (unsigned int j = 0; j < d; ++j) {
            sumf += factorials[digits[j]];
        }
        if (i == sumf) {
            totalsum += i;
        }
    }

    cout << "The sum of all numbers which are equal to"
         << "\nthe sum of the factorial of their digits is: "
         << totalsum << endl;
}
