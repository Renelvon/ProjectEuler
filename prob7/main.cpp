#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<unsigned int> primes;
    const unsigned int nthPrime = 10001;

    primes.push_back(2);

    bool flag;
    for (unsigned int i = 3; primes.size() < nthPrime; ++i) {
        flag = true;
        for (unsigned int j = 0; j < primes.size(); ++j) {
            if (0 == i % primes[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primes.push_back(i);
        }
    }

    cout << "The " << nthPrime << "th prime is: " << primes.back() << endl;
}
