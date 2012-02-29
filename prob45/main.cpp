#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Every hexagonal number is a triangle number, too!
    const unsigned long int maxH = 10000000000, minH = 40755;

    vector<unsigned long int> pent;

    for (unsigned long int i = 1; i * (3 * i - 1) / 2 < maxH; ++i) {
        pent.push_back(i * (3 * i - 1) / 2);
    }

    unsigned long int i;
    for (i = 1; i * (2 * i - 1) < maxH; ++i) {
        if (i * (2 * i - 1) <= minH) {
            continue;
        }

        if (binary_search(pent.begin(), pent.end(), i * (2 * i - 1))) {
            break;
        }
    }

    cout << "The smallest triangle number greater than " << minH
         << "\nthat is also pentagonal and hexagonal is: "
         << i * (2 * i - 1) << endl;
}
