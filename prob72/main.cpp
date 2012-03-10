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

    unsigned long int sump = 0;
    for (unsigned int i = 2; i < intmax + 1; ++i) {
        sump += phi[i];
    }

    cout << "There are " << sump << " proper reduced fractions"
         << "\nwith denominators not exceeding " << intmax << "." << endl;
    
    delete[] phi;
}
