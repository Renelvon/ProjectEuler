#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const unsigned int target = 100;
    /* ways[i][j] is the number of ways j can be written
     * as a sum of one or more positive integers not exceeding i.
     */
    unsigned int ways[target + 1][target + 1], sum;
    fill(ways[0], ways[0] + target + 1, 0);
    fill(ways[1] + 1, ways[1] + target + 1, 1);
    for (unsigned int i = 1; i < target + 1; ++i) {
        ways[i][0] = 0;
    }
    for (unsigned int i = 2; i < target + 1; ++i) {
        for (unsigned int j = 1; j < target + 1; ++j) {
            sum = 0;
            for (unsigned int k = 1; k < i + 1 && k < j; ++k) {
                sum += ways[k][j - k];
            }
            ways[i][j] = sum + (i < j ? 0 : 1);
        }
    }

    cout << "There are " << (0 == target ? 0 : (ways[target][target] - 1))
         << " ways to write " << target
         << " as a sum of at least two positive integers." << endl;
}
