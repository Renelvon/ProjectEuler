#include <iostream>
#include <string>

using namespace std;

int romanToInt(const char r) {
    switch (r) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            cerr << "Non-roman input" << endl;
            break;
        }
    return 0;
}

int main() {
    int count, num, temp, prev;
    string roman;
    do {
        cin >> roman;
        count = roman.size();
        prev = romanToInt(roman[0]);
        num = 0;
        for (unsigned int i = 1; i < roman.size(); ++i) {
            temp = romanToInt(roman[i]);
            if (prev < temp) {
                num -= prev;
            } else {
                num += prev;
            }
            prev = temp;
        }
        num += prev;

        cout << num << " " << count << endl;
    } while (!cin.eof());
}
