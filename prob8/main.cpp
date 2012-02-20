#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class CInt {
    public:
        inline
        unsigned int operator() (const char alpha) const {
            return atoi(&alpha);
        }
};

int main() {
    string all1000Digits;
    cin >> all1000Digits;

    vector<unsigned int> singleDigits;
    singleDigits.reserve(1000);

    transform (all1000Digits.begin(), all1000Digits.end(),
               back_inserter(singleDigits),
               CInt());

    unsigned int product, maxProduct(0);

    vector<unsigned int>::iterator iter;

    for(iter = singleDigits.begin(); iter < singleDigits.end() - 5; ++iter) {
        product = accumulate (iter, iter + 5, 1, multiplies<unsigned int>());
        maxProduct = max(product, maxProduct);
    }

    cout << "The maximum product of 5 consecutive digits of the string is: "
         << maxProduct << endl;
}
