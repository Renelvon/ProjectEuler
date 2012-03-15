#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct triple {
    unsigned int a, b, c;
};

int main() {
    const unsigned int intmax = 10000;
    unsigned int count = 0;

    triple cur;
    vector<triple> v;

    bool parity, found;
    for (unsigned int i = 1, j = 1; i < intmax + 1; ++i) {
        while ((j + 1) * (j + 1) <= i) {
            ++j;
        }
        if (i == j * j) {
            continue;
        }
        
        // Initial
        cur.a = cur.c = j;
        cur.b = 1;

        v.clear();
        v.push_back(cur);

        parity = false;
        for (;; parity = !parity) {
            /* transformation:
             * (sqrt(n) - a_{i}) / b_{i}) ->
             * -> 1 / (c_{i + 1} + (sqrt(n) - a_{i + 1}) / b_{i + 1})
             */
            cur.b = (i - cur.a * cur.a) / cur.b;
            cur.c = static_cast<unsigned int>(sqrt(i) + cur.a) / cur.b;
            cur.a = cur.b * cur.c - cur.a;
            found = false;
            for (unsigned int i = 0; !found && i < v.size(); ++i) {
                if (v[i].a == cur.a &&
                    v[i].b == cur.b &&
                    v[i].c == cur.c) {
                    found = true;
                }
            }
            if (found) {
                break;
            }
            v.push_back(cur);
        }
        if (parity) {
            ++count;
        }
    }

    cout << "There are " << count << " continued fractions for N <= " << intmax
         << "\nwhich have an odd period." << endl;
}
