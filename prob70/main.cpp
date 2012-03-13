#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const unsigned long int intmax = 10000000;

    unsigned long int *phi = new unsigned long int[intmax + 1];
    for (unsigned long int i = 0; i < intmax + 1; ++i) {
        phi[i] = i;
    }

    for (unsigned long int i = 2; i < intmax + 1; ++i) {
        if (i == phi[i]) {
            --phi[i];
            for (unsigned long int j = 2 * i; j < intmax + 1; j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }

    unsigned long int bestn = intmax, bestphi = 1, di, dp, numi, nump;
    unsigned int digitsi[10], digitsp[10];
    for (unsigned long int i = 2; i < intmax; ++i) {
        if (i > 10 * phi[i]) {
            continue; // Ignore solutions with non-equal number of digits
        }
        numi = i;
        di = 0;
        do {
            digitsi[di] = numi % 10;
            numi /= 10;
            ++di;
        } while (numi > 0);

        nump = phi[i];
        dp = 0;
        do {
            digitsp[dp] = nump % 10;
            nump /= 10;
            ++dp;
        } while (nump > 0);

        sort(digitsi, digitsi + di);
        sort(digitsp, digitsp + dp);

        if (equal(digitsi, digitsi + di, digitsp)) {
            if (i * bestphi < bestn * phi[i]) {
                bestn = i;
                bestphi = phi[i];
            }
        }
    }

    cout << "The value of 1 < n < " << intmax << " for which phi(n)"
         << "\nis a pemrmutation of n and n/phi(n) is minimum is: "
         << bestn << endl;
    
    delete[] phi;
}
