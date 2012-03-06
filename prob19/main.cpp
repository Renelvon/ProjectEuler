#include <iostream>

using namespace std;

int main() {
    // Year 1990 was a leap year, so it had 366 days.
    // Since 1 Jan 1900 was Monday and 364 / 7 = 52,
    // then 30 Dec 1900 was Monday, so 1 Jan 1901 was Wednesday = 3rd day.
    // Each time the 'days' is an even multiple of 7 at the start of a month,
    // one more Sunday fell at the 1st of the month.
    unsigned int days = 3, count = (0 == days % 7) ? 1 : 0;
    for (unsigned int year = 1901; year < 2001; ++year) {
        for (unsigned int i = 1; i < 13; ++i) {
            switch (i) {
                case 1:  // January
                case 3:  // March
                case 5:  // May
                case 7:  // July
                case 8:  // August
                case 10: // October
                case 12: // December
                    days += 31;
                    break;
                case 2:  // February. Check for leap year.
                    days += (0 == year % 4) ?
                                (0 == year % 100) ?
                                    (0 == year % 400) ?
                                        29
                                        : 28
                                    : 29
                                : 28;
                    break;
                case 4:  // April
                case 6:  // June
                case 9:  // September
                case 11: // November
                    days += 30;
                    break;
            }
            if (0 == days % 7) {
                ++count;
            }
        }
    }
    
    cout << count << " Sundays fell on the first of the month"
         << "\nduring the twentieth century (1 Jan 1901 to 31 Dec 2000)."
         << endl;
}
