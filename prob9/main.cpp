#include <iostream>

using namespace std;

int main() {
    const unsigned int sum = 1000;
    unsigned int a = 1, b = 0;

    while (1000 * (a + b) != (1000 * 500 + a * b)) {
        ++b;
        if (998 == b) {
            b = 0;
            ++a;
        }
    }

    cout << "The only pythagorean triplet {a, b, c} for which "
         << "a + b + c = " << sum << " \nis: {" << a << ", "
         << b << ", " << sum - a - b << "} and "
         << "abc = " << a * b * (sum - a - b) <<  endl;
}
