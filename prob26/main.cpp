#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const unsigned int intmax = 1000;

    unsigned int count, maxcount = 0, maxd = 1, num, denum;
    unsigned int modulus[intmax];
    for (unsigned int i = 2; i < intmax; ++i) {
        fill(modulus, modulus + i + 1, 0);
        count = 0;
        num = 1;
        denum = i;
        for (;;) {
            ++count;
            if (num > denum) {
                num %= denum;

                if (0 == num) {
                    count = 0;
                    break;
                } 

                if (modulus[num] > 0) {
                    count -= modulus[num];
                    break;
                } else {
                    modulus[num] = count;
                }
            }

            num *= 10;
        } 

        if (count > maxcount) {
            maxcount = count;
            maxd = i;
        }
    }
        
    cout << "The value of d < " << intmax << " for which 1/d contains "
         << "\nthe longest recurring cycle in its decimal fraction part is: "
         << maxd << endl;
}
