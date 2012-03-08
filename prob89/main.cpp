#include <iostream>

using namespace std;

int main() {
    int num, count, saved = 0;
    // rdigits[i] is the number of roman numerals needed to write i.
    int rdigits[10] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
    while (!cin.eof()) {
        cin >> num >> count;
        if (num < 1) {
            break;
        }
        saved += count;

        count = num / 1000;
        num %= 1000; 

        while (num > 0) {
            count += rdigits[num % 10];
            num /= 10;
        }
        
        saved -= count;
    }

    cout << "The number of characters saved by writing all roman numerals"
         << "\nin their minimal form is: " << saved << endl;
}
