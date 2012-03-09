#include <iostream>

using namespace std;

int main() {
    const unsigned long int intmax = 1000000;

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

    unsigned long int bestn = 0, bestphi = 1;
    for (unsigned long int i = 1; i < intmax + 1; ++i) {
        if (i * bestphi > bestn * phi[i]) {
            bestn = i;
            bestphi = phi[i];
        }
    }

    cout << "The value of n <= " << intmax << " for which n/φ(n)"
         << "\nis a maximum is: " << bestn << endl;
    
    delete[] phi;
}
