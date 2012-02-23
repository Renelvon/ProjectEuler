#include <iostream>

using namespace std;

int main() {
    const unsigned int size = 1001;
    long int sum = -3;

    /* North-east sequence: a_n = (2 * n + 1) * (2 * n + 1)
     * North-west sequence: b_n = a_n - 2 * n
     * South-west sequence: c_n = a_n - 4 * n
     * South-east sequence: d_n = a_n - 6 * n
     * where a_0 = b_0 = c_0 = d_0 = 1.
     * nth term of sum: s_n = a_n + b_n + c_n + d_n
     *                  s_n = 16 * n * n + 4 * n + 4
     * Total sum: -3 + \sum_{n = 0}^{(size + 1) / 2 - 1}  s_n [only count the 1 once]
     */
    for (unsigned int i = 0; i < (size + 1) / 2; ++i) {
        sum += 4 * ((4 * i + 1) * i + 1);
    }

    cout << "The sum of the numbers appearing on the diagonals of a\n"
         << size << " * " << size << " number spiral is: " << sum << endl;
}
