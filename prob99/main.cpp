#include <cmath>
#include <iostream>

using namespace std;

int main() {
    unsigned int count, base, expo, tbase, texpo, line;
    cin >> count >> base >> expo; // Assuming count >= 1.
    line = 1;

    for (unsigned int i = 2; i < count + 1; ++i) {
        cin >> tbase >> texpo;
        if (static_cast<double>(expo) * log(static_cast<double>(base)) <
            static_cast<double>(texpo) * log(static_cast<double>(tbase))) {
            base = tbase;
            expo = texpo;
            line = i;
        }
    }

    cout << "The line which has the base/exponent pair"
         << "\nwith the greatest numeric value is: " << line << endl;
}
