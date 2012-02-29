#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    unsigned int N, L;
    cin >> N >> L;

    unsigned int maxT = 26 * L;
    vector<unsigned int> triangArr;
    for (unsigned int i = 1; i * (i + 1) / 2 < maxT + 1; ++i) {
        triangArr.push_back(i * (i + 1) / 2);
    }

    unsigned int count = 0, score;
    const unsigned int Aint = static_cast<unsigned int>('A');
    string temp;
    for (unsigned int i = 0; i < N; ++i) {
        cin >> temp;
        score = 0;
        for (unsigned int j = 0; j < temp.size(); ++j) {
            score += static_cast<unsigned int>(temp[j]) - Aint + 1;
        }
        if (binary_search(triangArr.begin(), triangArr.end(), score)) {
            ++count;
        }
    }

    cout << "There are " << count << " triangle words in the file." << endl;
}
