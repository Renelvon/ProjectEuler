#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const unsigned long int maxP = 10000000;

    vector<unsigned long int> pent;

    for (unsigned long int i = 1; i * (3 * i - 1) / 2 < maxP; ++i) {
        pent.push_back(i * (3 * i - 1) / 2);
    }

    unsigned long int i, j, mind = maxP;
    for (i = 0; i < pent.size() ; ++i) {
        for (j = i + 1; j < pent.size(); ++j) {
            if (binary_search(pent.begin(), pent.end(), pent[j] - pent[i]) &&
                binary_search(pent.begin(), pent.end(), pent[j] + pent[i])
               ) {
                mind = min(mind, pent[j] - pent[i]);
            }
        }
    }

    cout << "The pair of pentagonal numbers, Pj and Pk, for which their"
         <<"\nsum and difference is pentagonal and D = |Pk - Pj| is minimised"
         << " has D: " << mind << endl;
}
