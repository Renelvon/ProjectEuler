#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 1000000;
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(max));

    bool prime[max];
    fill(prime, prime + max, true);
    prime[0] = false;
    prime[1] = false;
    for (unsigned int i = 4; i < max; i += 2) {
         prime[i] = false;
    }
    for (unsigned int i = 3; i < sqmax + 1; i += 2) {
        if (prime[i]) {
            for (unsigned int j = i * i; j < max; j += 2*i) {
                prime[j] = false;
            }
        }
    }

    unsigned int count = 0;
    for (unsigned int i = 0; i < max; ++i) {
        if (prime[i]) {
            ++count;
        }
    }

    unsigned int n = 1;
    unsigned long int sum = 0, *sump = new unsigned long int[count + 1];
   
    sum = 0;
    sump[0] = 0;
    for (unsigned int i = 2; i < max; ++i) {
        if (prime[i]) {
            sum += i;
            sump[n] = sum;
            ++n;
        }
    }
    
    unsigned long int bestsum = 0, bestcount = 0;
    for (unsigned int i = 1; i < n; ++i) {
        for (unsigned int j = n; j-- > i; ) {
            sum = sump[j] - sump[i - 1];
            if (sum > max) {
                continue;
            }
            count = j - i + 1;
            if (sum < max && prime[sum] && count > bestcount) {
                bestsum = sum;
                bestcount = count;
            }
        }
    }

    cout << "The prime below " << max << " which can be written"
         << "\nas the sum of the most consecutive primes is: "
         << bestsum << ". The sum contains " << bestcount << " terms." << endl;

    delete[] sump;
}
