#include <iostream>

using namespace std;

int main() {
   const unsigned int max = 2000000;
   unsigned long int sump = 0;

   bool prime[max];
   fill(prime, prime + max, true);
   prime[0] = false;
   prime[1] = false;
   for (unsigned int i = 2; i < max; ++i) {
       if (prime[i]) {
           sump += i;
           for (unsigned int j = 2 * i; j < max; j += i) {
               prime[j] = false;
           }
       }
   }
   cout << "The sum of all primes below " << max
        << " is: " << sump << endl;
}
