#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    const unsigned int max = 1000, mul1 = 3, mul2 = 5;
    unsigned int maxind1 = (max - 1) / mul1,
                 maxind2 = (max - 1) / mul2,
                 maxind3 = (max - 1) / (mul1 * mul2),
                 sum1 = mul1 * maxind1 * (maxind1 + 1),
                 sum2 = mul2 * maxind2 * (maxind2 + 1),
                 sum3 = mul1 * mul2 * maxind3 * (maxind3 + 1),
                 sum = (sum1 + sum2 - sum3) / 2;

    cout << "Sum of numbers below " << max << " that are multiples of "
         << mul1 << " or " << mul2 << " : "
         << sum << endl;

    return EXIT_SUCCESS;
}
