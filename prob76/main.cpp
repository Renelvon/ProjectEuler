#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const unsigned int target = 100;
    /* ways[n][i] is the number of ways n can be written
     * as a sum of one or more positive integers not exceeding i.
     */
    unsigned int ways[target + 1][target + 1], sum;
    fill(ways[0], ways[0] + target + 1, 0);
    fill(ways[1] + 1, ways[1] + target + 1, 1);
    for (unsigned int n = 1; n < target + 1; ++n) {
        ways[n][0] = 0;
    }
    for (unsigned int n = 2; n < target + 1; ++n) {
        for (unsigned int i = 1; i < n; ++i) {
            sum = 0;
            for (unsigned int j = 1; j < i + 1; ++j) {
                sum += ways[n - j][j];
            }
            ways[n][i] = sum;
        }
        ways[n][n] = ways[n][n - 1] + 1;
        fill(ways[n] + n, ways[n] + target + 1, ways[n][n]);
    }

    cout << "There are " << (0 == target ? 0 : (ways[target][target] - 1))
         << " ways to write " << target
         << " as a sum of at least two positive integers." << endl;
}
