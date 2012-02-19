#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 100;
    unsigned long int sum = 0;

    /* (\sum_{i = 0}^{max} i)^2 - \sum_{i = 0}^{max} i^2 =
     * = \sum_{i = 0}^{max} \sum_{j = 0, i \neq j}^{max} (2ij)
     * = 2 \sum_{i = 0}^{max} (i \sum_{j = 0, i \neq j}^{max} j)
     * = 2 \sum_{i = 1}^{max} (i (max(max + 1) / 2 - i))
     */
    for (unsigned int i = 1; i < max + 1; ++i) {
        sum += i * (max * (max + 1) / 2 - i);
    }

    cout << "The difference between (1 + 2 + 3 + ... + "
         << max << ")^2 and (1^2 + 2^2 + 3^2 + ... + "
         << max << "^2) is: " << sum << endl;
}
