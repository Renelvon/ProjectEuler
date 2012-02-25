#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    /* NOTE: It suffices to consider products of the form m1 * m2 = m
     * where either: m1 has 4 digits and m2 has 1 digit
     *       or    : m1 has 3 digits and m2 has 2 digits
     */
    unsigned int m, m1, sump = 0;
    unsigned int digits[10];
    bool flag;
    vector<unsigned int> prod;

    // Phase 1: m1 has 4 digits, m2 has 1 digit
    for (unsigned int m2 = 1; m2 < 10; ++m2) {
        m1 = 1234;
        do {
            m = m1 * m2;
            fill(digits, digits + 10, 0);

            for (unsigned int d = m, r; d > 0; d /= 10) {
                r = d % 10;
                digits[r]++;
            }

            for (unsigned int d = m1, r; d > 0; d /= 10) {
                r = d % 10;
                digits[r]++;
            }

            for (unsigned int d = m2, r; d > 0; d /= 10) {
                r = d % 10;
                digits[r]++;
            }
            
            flag = (digits[0] == 0);
            for (unsigned int idx = 1; idx < 10; ++idx) {
                if (digits[idx] != 1) {
                    flag = false;
                }
            }

            if (flag) {
                prod.push_back(m);
            } 

            ++m1;
        } while (m1 < 9877);
    }

    // Phase 2: m1 has 3 digits, m2 has 2 digit
    for (unsigned int m2 = 12; m2 < 99; ++m2) {
        if (0 == m2 % 10 || 0 == m2 % 11) {
            continue;
        }
        m1 = 123;
        do {
            m = m1 * m2;
            fill(digits, digits + 10, 0);

            for (unsigned int d = m, r; d > 0; d /= 10) {
                r = d % 10;
                digits[r]++;
            }

            for (unsigned int d = m1, r; d > 0; d /= 10) {
                r = d % 10;
                digits[r]++;
            }

            for (unsigned int d = m2, r; d > 0; d /= 10) {
                r = d % 10;
                digits[r]++;
            }
            
            flag = (digits[0] == 0);
            for (unsigned int idx = 1; idx < 10; ++idx) {
                if (digits[idx] != 1) {
                    flag = false;
                }
            }

            if (flag) {
                prod.push_back(m);
            } 

            ++m1;
        } while (m1 < 988);
    }

    // Remove duplicates.
    sort(prod.begin(), prod.end());
    sump = accumulate(prod.begin(),
                      unique(prod.begin(), prod.end()),
                      0);
    cout << "The sum of numbers of all products whose"
         << " multiplicand/multiplier/product identity"
         << "\ncan be written as a 1 through 9 pandigital is: "
         << sump << endl;
}
