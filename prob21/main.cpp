#include <iostream>

using namespace std;

int main() {
    const unsigned int limit = 10000;
    unsigned int sumall = 0;

    unsigned int sumdiv[limit + 1];
    fill(sumdiv, sumdiv + limit + 1, 0);

    for(unsigned int i = 1, sum; i < limit + 1; ++i) {
        sum = 0;
        for (unsigned int j = 1; j < i / 2 + 1; ++j) {
            if (0 == i % j) {
                sum += j;
            }
        }
        sumdiv[i] = sum;
        if (sumdiv[i] < i && i == sumdiv[sumdiv[i]]) {
            sumall += i + sumdiv[i];
        }
    }

    cout << "The sum of all amicable numbers not exceeding " << limit
         << " is: " << sumall << endl;
}
