#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 10000;
    const unsigned int sqmax = static_cast<unsigned int>(sqrt(max));

    bool *prime = new bool [max];
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

    bool *conj = new bool [max];
    fill(conj, conj + max, false);
    for (unsigned int i = 2; i < max; ++i) {
        if (prime[i]) {
            for (unsigned int j = 1; i + 2 * j * j < max; ++j){
                conj[i + 2 * j * j] = true;
            }
        }
    }
    
    unsigned int minf = 9;
    for (minf = 9; minf < max; minf += 2) {
        if (!prime[minf] && !conj[minf]) {
            break;
        }
    }

    cout << "The smallest odd composite number <= " << max
         << " that cannot be written"
         << "\nas the sum of a prime and twice a square is: "
         << (minf > max ? 0 : minf) << endl;

    delete [] prime;
    delete [] conj;
}
