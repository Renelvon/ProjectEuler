#include <iostream>

using namespace std;

int main() {
    const unsigned int num = 3, denum = 7, denummax = 1000000;

    unsigned int bestnum = 1, bestdenum = denummax, tempnum;
    for (unsigned int i = 1; i < denummax + 1; ++i) {
        if (0 == (num * i) % denum) {
            tempnum = (num * i) / denum - 1;
        } else {
            tempnum = (num * i) / denum;
        }

        if (tempnum * bestdenum > bestnum * i) {
            bestnum = tempnum;
            bestdenum = i;
        }
    }

    cout << "If we list the set of reduced proper fractions with denominators"
         << "\nnot exceeding " << denummax << " in ascending order of size,"
         << "\nthe numerator of the fraction immediately to the left of "
         << num << "/" << denum << " is: " << bestnum << endl;

}
