#include <cmath>
#include <iostream>

using namespace std;

int main() {
    unsigned int rows, columns;
    cin >> rows >> columns;

    unsigned int **G = new unsigned int* [rows];
    for (unsigned int i = 0; i < rows; ++i) {
        G[i] = new unsigned int [columns];
        for (unsigned int j = 0; j < columns; ++j) {
            cin >> G[i][j];
        }
    }

    for (unsigned int j = columns - 1; j-- > 0; ) {
        G[rows - 1][j] += G[rows - 1][j + 1];
    }

    for (unsigned int i = rows - 1; i-- > 0; ) {
        G[i][columns - 1] += G[i + 1][columns - 1];
    }

    for (unsigned int i = rows - 1; i-- > 0; ) {
        for (unsigned int j = columns - 1; j-- > 0; ) {
            G[i][j] += min(G[i + 1][j], G[i][j + 1]);
        }
    }

    cout << "The minimal path sum for moving from the top left to the bottom right"
         << " in the given matrix is: " << G[0][0] << endl;

    for (unsigned int i = 0; i < rows; ++i) {
        delete [] G[i];
    }
    delete [] G;
}
