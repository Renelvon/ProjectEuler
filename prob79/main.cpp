#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Assuming code does not contain repeated digits.
int main() {
    unsigned int tries;
    cin >> tries;

    bool digits[10][10], exists[10];
    for (unsigned int i = 0; i < 10; ++i) {
        fill(digits[i], digits[i] + 10, false);
    }
    fill(exists, exists + 10, false);

    unsigned int d1, d2, d3, s, cand;
    for (unsigned int i = 0; i < tries; ++i) {
        cin >> d1 >> d2 >> d3;
        digits[d1][d2] = true;
        digits[d2][d3] = true;
        digits[d1][d3] = true;
        exists[d1] = exists[d2] = exists[d3] = true;
    }

    cout << "Assuming each digit appears only once, "
         << "\nthe shortest possible passcode is: ";

    while ((exists + 10) != find(exists, exists + 10, true)) {
        cand = 0;
        s = 1;
        for (;;) {
            if (!exists[cand]) {
                ++cand;
                s = cand + 1;
            } else if (s < 10 && exists[s] && digits[s][cand]) {
                cand = s;
                ++s;
            } else if (s < 10) {
                ++s;
            } else {
                break;
            }
        }
        fill(digits[cand], digits[cand] + 10, false);
        exists[cand] = false;
        cout << cand;
    }

    cout << endl;
}
