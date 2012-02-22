#include <algorithm>
#include <iostream>

using namespace std;

int main () {
    unsigned int rows;
    cin >> rows;

    unsigned int **num = new unsigned int* [rows];
    for (unsigned int i = 0; i < rows; ++i) {
        num[i] = new unsigned int [i + 1];
        for (unsigned int j = 0; j < i + 1; ++j) {
            cin >> num[i][j];
        }
    }

    unsigned int *sol = new unsigned int [rows + 1];
    fill(sol, sol + rows + 1, 0);

    for (unsigned int i = rows; i-- > 0; ) {
        for (unsigned int j = 0; j < i + 1; ++j) {
            sol[j] = num[i][j] + max(sol[j], sol[j + 1]);
        }
    }

    cout << "The maximum sum travelling from the top to the bottom"
         << " of the triangle is: " << sol[0] << endl;

    for (unsigned int i = 0; i < rows; ++i) {
        delete [] num[i];
    }
    delete [] num;
    delete [] sol;
}
