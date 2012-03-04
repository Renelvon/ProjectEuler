#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const unsigned int intmax = 28124, allsum = intmax * (intmax - 1) / 2;

    unsigned int num, divisors[intmax];
    divisors[0] = 0;
    fill(divisors + 1, divisors + intmax, 1);
    vector<unsigned int> abNums;
    for (unsigned int i = 2; i < intmax; ++i) {
        if (divisors[i] > i) {
            abNums.push_back(i);
        }

        num = 2 * i;
        while (num < intmax) {
            divisors[num] += i;
            num += i;
        }
    }

    bool isSumAbundant[intmax];
    fill(isSumAbundant, isSumAbundant + intmax, false);

    unsigned int curAb, sum2Abund = 0;
    vector<unsigned int>::const_iterator pos;
    while (!abNums.empty()) {
        curAb = abNums.back();
        for(pos = abNums.begin();
            curAb + *pos < intmax && pos != abNums.end();
            ++pos) {
            isSumAbundant[curAb + *pos] = true;
        }
        abNums.pop_back();
    }

    for (unsigned int i = 0; i < intmax; ++i) {
        if (isSumAbundant[i]) {
            sum2Abund += i;
        }
    }
    cout << "The sum of all numbers less than " << intmax
         << "\nwhich cannot be written as a sum of 2 abundant numbers is: "
         << allsum - sum2Abund << endl;
}
