#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    const unsigned int max = 4000000;
    unsigned long int sum = 0;
    unsigned int fprev = 0, fcurr = 0, fnext = 2;

    // Concerning Fibonacci sequence: F_{n + 3} = 4 F_{n} + F_{n + 3}
    do {
        sum += fnext;
        fprev = fcurr;
        fcurr = fnext;
        fnext = 4 * fcurr + fprev;
    } while (fnext <= max);

    cout << "The sum of all even Fibonacci numbers not exceeding " << max
         << " is: " << sum << endl;

    return EXIT_SUCCESS;
}
