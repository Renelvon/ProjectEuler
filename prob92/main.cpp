#include <algorithm>
#include <iostream>

using namespace std;

enum calcState {Unknown, Fix1, Fix89};
static calcState *calcArr;

/* For numbers less than 10000000, the sum of the digit's squares
 * is at most 7 * 9 * 9
 */
const unsigned int calcmax = 7 * 9 * 9;

calcState getFinal (const unsigned int n) {
    unsigned int d = n, sqsum = 0;
    do {
        sqsum += (d % 10) * (d % 10);
        d /= 10;
    } while (d > 0);
    
    if (n > calcmax) {
        return calcArr[sqsum];
    }

    calcArr[n] = (Unknown == calcArr[sqsum])
                 ? getFinal(sqsum)
                 : calcArr[sqsum];

    return calcArr[n];
}

int main() {
    const unsigned int intmax = 10000000;

    calcArr = new calcState[calcmax + 1];

    fill(calcArr, calcArr + calcmax + 1, Unknown);
    calcArr[1] = Fix1;
    calcArr[89] = Fix89;
    for (unsigned int i = 1; i < calcmax + 1; ++i) {
        if (Unknown == calcArr[i]) {
            calcArr[i] = getFinal(i);
        }
    }

    unsigned int sum89 = 0;
    for (unsigned int i = 0; i < intmax; ++i) {
        if (i > calcmax) {
            if (Fix89 == getFinal(i)) {
                ++sum89;
            }
        } else if (Fix89 == calcArr[i]) {
            ++sum89;
        }
    }

    cout << "There are " << sum89 << " numbers starting below " << intmax
         << "\nwhich arrive at 89 if their digits are repeatedly"
         << " squared and summed." << endl;

    delete[] calcArr;
}
