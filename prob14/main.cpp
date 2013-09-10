#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

unsigned int *length;

int main () {
    const unsigned int limit = 1000000;

    length = new unsigned int [limit];
    fill(length, length + limit, 0);
    length[1] = 1;

    vector<unsigned int> seq;
    for (unsigned int i = 2; i < limit; ++i) {
        seq.clear();
        // Generate sequence until a term of known degree is reached.
        seq.push_back(i);
        while (seq.back() >= limit || 0 == length[seq.back()]) {
            if (0 == seq.back() % 2) {
                seq.push_back(seq.back() / 2);
            } else {
                seq.push_back(3 * seq.back() + 1);
            }
        }
        // Update previously unknown degrees
        for (unsigned int d = length[seq.back()] + seq.size() - 1, j = 0;
             j < seq.size(); ++j) {
            if (seq[j] < limit && 0 == length[seq[j]]) {
                length[seq[j]] = d - j;
            }
        }
    }

    unsigned int max = 0, imax = 0;
    for (unsigned int i = 0; i < limit; ++i) {
        if (length[i] > max) {
            max = length[i];
            imax = i;
        }
    }

    cout << "The number that produces the longest chain in the Collatz"
         << " sequence and is under " << limit << " is: " << imax << endl;

    delete [] length;
}
