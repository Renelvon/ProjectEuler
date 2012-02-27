#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const unsigned int pmax = 1000;

    // (a = 3, b = 4, c = 5) is the smallest integer right angle trangle.
    unsigned int sols, solsbest = 1, pbest = 12;
    for (unsigned int p = 3; p < pmax + 1; ++p) {
        sols = 0;
        for (unsigned int c = 5; c < p; ++c) {
            for (unsigned int b = 4; (b < c + 1) && (b + c) < p; ++b) {
                if (p * p + 2 * b * b == 2 * (p * (b + c) - b * c)) {
                    ++sols;
                }
            }
        }
        if (sols > solsbest) {
            pbest = p;
            solsbest = sols;
        }
    }

    cout << "The perimetre p (where p <= " << pmax << ")"
         << "\nfor which there exist the most right angle triangles is: "
         << pbest << endl;
}
