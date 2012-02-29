#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    const unsigned int max = 10000;

    unsigned int d, dold, n, num, maxnum = 918273645;
    unsigned int digits[20];
    bool flag;
    for (unsigned int i = 1; i < max; ++i) {
        flag = true;
        dold = 0;
        d = 0;
        for (n = 1; d < 9; ++n) {
            num = i * n;
            do {
                digits[d] = num % 10;
                num /= 10;
                ++d;
            } while (num > 0);
            reverse(digits + dold, digits + d);
            dold = d;
        }

        if (9 == d) {
            num = 0;
            for (unsigned int j = 0; flag && j < d; ++j) {
                num = num * 10 + digits[j];
            }

            sort(digits, digits + d);
            for (unsigned int j = 0; flag && j < d; ++j) {
                flag = digits[j] == (j + 1);
            }

            if (flag && num > maxnum) {
                maxnum = num;
            }
        }
    }

    cout << "The largest 1 to 9 pandigital 9-digit number that can be formed"
         << "\nas the concatenated product of an integer with (1, 2, ..., n)"
         << "\nwhere n > 1 is: " << maxnum << endl;
}
