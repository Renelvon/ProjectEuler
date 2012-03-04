#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    unsigned int digits[10];
    for (unsigned int i = 0; i < 10; ++i) {
        digits[i] = i;
    }

    unsigned long int sump = 0, num;
    do {
        if (0 == (digits[7] * 100 + digits[8] * 10 + digits[9]) % 17 &&
            0 == (digits[6] * 100 + digits[7] * 10 + digits[8]) % 13 &&
            0 == (digits[5] * 100 + digits[6] * 10 + digits[7]) % 11 &&
            0 == (digits[4] * 100 + digits[5] * 10 + digits[6]) % 7 &&
            0 == (digits[3] * 100 + digits[4] * 10 + digits[5]) % 5 &&
            0 == (digits[2] * 100 + digits[3] * 10 + digits[4]) % 3 &&
            0 == (digits[1] * 100 + digits[2] * 10 + digits[3]) % 2
           ) {
            num = 0;
            for (unsigned int i = 0; i < 10; ++i) {
                num = num * 10 + digits[i];
            }
            sump += num;
        }
    } while (next_permutation(digits, digits + 10));

    cout << "The sum of all 0 to 9 pandigital numbers with the sub-string"
         << "\ndivisibility property demanded by ProjectEuler problem 43 is: "
         << sump << endl;
}
