#include <algorithm>
#include <iostream>

using namespace std;

bool isPalindrome6 (unsigned int number) {
    if (    (number / 100000)      ==  (number % 10)
        && ((number / 10000) % 10) == ((number % 100) / 10)
        && ((number / 1000) % 10)  == ((number % 1000) / 100)
       )
        return true;
    return false;
}

int main() {
    unsigned int number = 0, candidate = 0;

    for (unsigned int a = 999; a > 99; --a) {
        for (unsigned int b = a; b > 99; --b) {
            candidate = a * b;
            if (isPalindrome6(candidate)) {
                number = max(candidate, number);
                break;
            }
            if (candidate < number) {
                break;
            }
        }

    }

    cout << "The largest palindrome made from the product of two "
         << "3-digit numbers is: " << number << endl;
}
