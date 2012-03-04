#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned int size = 50;
    
    /* There are size * size cases where P is on y'y and
     * Q is on x'x and <POQ is a right angle.
     * There are size * size cases where P is on y'y and
     * Q is on y = y_{P}, y_{P} \neq 0 and <OPQ is a right angle.
     * There are size * size cases where Q is on x'x and
     * P is on x = x_{Q}, x_{Q} \neq 0 and <OPQ is a right angle.
     */
    unsigned int count = 3 * size * size;

    /* Next, consider all pairs P, Q = (x1, y1), (x2, y2)
     * where <OPQ is a right angle and x1 > 0, y1 > 0.
    */
    for (unsigned int x1 = 1; x1 < size + 1; ++x1) {
        for (unsigned int y1 = 1; y1 < size + 1; ++y1) {
            for (unsigned int x2 = 0; x2 < size + 1; ++x2) {
                for (unsigned int y2 = 0; y2 < size + 1; ++y2) {
                    if ((x1 != 0 || y1 != 0) &&
                        (y2 != y1 || x2 != x1) &&
                        x1 * (x2 - x1) == y1 * (y1 - y2)
                       ) { // Right-angle
                        ++count;
                    }
                }
            }
        }
    }

    cout << "The number of right triangles lying in the [0, " << size
         << "] x [0, " << size << "] quadrant"
         << "\nwith (0, 0) as one of their vertices is: " << count << endl;
}
