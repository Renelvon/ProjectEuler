#include <algorithm>
#include <iostream>

using namespace std;

int main () {
    unsigned int rows, columns, maxn = 0;

    cin >> rows >> columns;

    unsigned int **G = new unsigned int* [rows];
    for(unsigned int i = 0; i < columns; ++i) {
        G[i] = new unsigned int [columns];
        for (unsigned int j = 0; j < columns; ++j) {
            cin >> G[i][j];
        }
    }

    // Examine all rows
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j + 3 < columns; ++j) {
            maxn = max(maxn,
                       G[i][j] * G[i][j + 1] * G[i][j + 2] * G[i][j + 3]);
        }
    }

    // Examine all columns
    for (unsigned int i = 0; i + 3 < rows; ++i) {
        for (unsigned int j = 0; j < columns; ++j) {
            maxn = max(maxn,
                       G[i][j] * G[i + 1][j] * G[i + 2][j] * G[i + 3][j]);
        }
    }

    // Examine all diagonals
    for (unsigned int i = 0; i + 3 < rows; ++i) {
        for (unsigned int j = 0; j + 3 < columns; ++j) {
            maxn = max(maxn,
                       G[i][j] * G[i + 1][j + 1] * G[i + 2][j + 2] * G[i + 3][j + 3]);
        }
    }

    // Examine all co-diagonals
    for (unsigned int i = 0; i + 3 < rows; ++i) {
        for (unsigned int j = 0; j + 3 < columns; ++j) {
            maxn = max(maxn,
                       G[i + 3][j] * G[i + 2][j + 1] * G[i + 1][j + 2] * G[i][j + 3]);
        }
    }

    cout << "The maximum product of 4 in-line elements of the input matrix is: "
        << maxn << endl;

    for (unsigned int i = 0; i < rows; ++i) {
        delete [] G[i];
    }
    delete [] G;
}
