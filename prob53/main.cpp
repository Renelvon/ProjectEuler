#include <iostream>

using namespace std;

int main() {
    const unsigned int high = 100, limit = 1000000;
    unsigned int sum = 0, c[high + 2][high + 2];

    c[1][1] = 1;
    for (unsigned int row = 2; row < high + 2; ++row) {
       c[row][row] = 1;
       for (unsigned int column = row - 1; column > 1; --column) {
           c[row][column] = c[row - 1][column - 1] + c[row - 1][column];
           if (c[row][column] > limit) {
               ++sum;
           }
        }
        c[row][1] = 1;
    }
    sum += 1 > limit ? (2 * high + 1) : 0;
    //cout << c[23][11] << endl;

    cout << "For " << 1 << " <= n <= " << high << ", the number of values of C(n, r)"
         << " that exceed " << limit << " is: " << sum << endl;
}
