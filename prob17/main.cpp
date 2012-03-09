#include <iostream>

using namespace std;

int main() {
    const unsigned int ones[20] = {
        0, /* Although 'zero' has 4 chars, we place a 
              0 here for easiness when considering decades. */
        3, // 'one'
        3, // 'two'
        5, // 'three'
        4, // 'four'
        4, // 'five'
        3, // 'six'
        5, // 'seven'
        5, // 'eight'
        4, // 'nine'
        3, // 'ten'
        6, // 'eleven'
        6, // 'twelve'
        8, // 'thirteen'
        8, // 'fourteen'
        7, // 'fifteen'
        7, // 'sixteen'
        9, // 'seventeen'
        8, // 'eighteen'
        8  // 'nineteen'
    };

    const unsigned int decades[10] = {
        0, // --
        0, // --
        6, // 'twenty'
        6, // 'thirty'
        5, // 'forty'
        5, // 'fifty'
        5, // 'sixty'
        7, // 'seventy'
        6, // 'eighty'
        6, // 'ninety'
    };

    unsigned int count = 0;
    for (unsigned int i = 1; i < 1000; ++i) {
        if (99 < i) {
            count += ones[i / 100] + 7; // 'hundred' -> 7 letters
        }

        if (99 < i && 0 < i % 100) {
            count += 3; // 'and' -> 3 letters
        }

        if (19 < i % 100) {
            count += decades[i / 10 % 10] + ones[i % 10];
        } else {
            count += ones[i % 100];
        }
    };

    count += 11; // 'one thousand' -> 11 letters

    cout << "The total number of letters needed to spell out all numbers"
         << "\nfrom 1 to 1000 is: " << count << endl;
}
