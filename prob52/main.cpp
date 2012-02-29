#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 1000000;

    unsigned int digits1[8], digits[8];

    unsigned int i, d1, d, n, num;
    bool flag;

    i = 0;
    do {
        ++i;

        num = i;
        d1 = 0;
        do {
            digits1[d1] = num % 10;
            num /= 10;
            ++d1;
        } while (num > 0);
        sort(digits1, digits1 + d1);

        n = 1;
        do {
            ++n;

            num = i * n;
            d = 0;
            do {
                digits[d] = num % 10;
                num /= 10;
                ++d;
            } while (num > 0);

            flag = (d1 == d);
            if (flag) {
                sort(digits, digits + d);
                flag = equal(digits1, digits1 + d1, digits);
            }
        } while (n < 6 && flag);
    } while (i < max && !flag);

    cout << "The smallest positive integer, x, such that"
         << "\n2x, 3x, 4x, 5x, and 6x, contain the same digits is: "
         << ((i < max) ? i : 0) << endl;
}
