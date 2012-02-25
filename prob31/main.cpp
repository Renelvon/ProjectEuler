#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    const unsigned int target = 200;
    const unsigned int denom[8] = {1, 2, 5, 10, 20, 50, 100, 200};

    /* ways[n][i] is the number of ways an amount of n pennies can be written
     * as a sum of coin denominations not exceeding i.
     */
    unsigned int ways[target + 1][target + 1], sum;
    fill(ways[0], ways[0] + target + 1, 1);
    fill(ways[1] + 1, ways[1] + target + 1, 1);
    for (unsigned int n = 1; n < target + 1; ++n) {
        ways[n][0] = 0;
    }
    for (unsigned int n = 2; n < target + 1; ++n) {
        for (unsigned int i = 1; i < n + 1; ++i) {
            sum = 0;
            for (unsigned int j = 0; j < 8 && denom[j] < i + 1; ++j) {
                sum += ways[n - denom[j]][denom[j]];
            }
            ways[n][i] = sum;
        }
        fill(ways[n] + n + 1, ways[n] + target + 1, ways[n][n]);
    }

    cout << "There are " << ways[target][target] << " ways to make "
         << target << " pennies"
         << "\nusing any number of coins of the denominations: " << endl;
    copy(denom, denom + 8,
         ostream_iterator<unsigned int>(cout, " ")
        );
    cout << endl;
}
