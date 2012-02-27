#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned int N;
    cin >> N;

    const unsigned int Aint = static_cast<unsigned int>('A');
    unsigned long int score, sum = 0;
    string temp;
    for (unsigned int i = 0; i < N; ++i) {
        cin >> temp;
        score = 0;
        for (unsigned int j = 0; j < temp.size(); ++j) {
            score += static_cast<unsigned int>(temp[j]) - Aint + 1;
        }
        sum += score * (i + 1);
    }

    cout << "The total of all the name scores in the file is: "
         << sum << endl;
}
