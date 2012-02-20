#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class CInt {
    public:
        inline
        unsigned int operator() (const char alpha) const {
            return atoi(&alpha);
        }
};

int main() {
    string all1000Digits;
    all1000Digits.append("73167176531330624919225119674426574742355349194934");
    all1000Digits.append("96983520312774506326239578318016984801869478851843");
    all1000Digits.append("85861560789112949495459501737958331952853208805511");
    all1000Digits.append("12540698747158523863050715693290963295227443043557");
    all1000Digits.append("66896648950445244523161731856403098711121722383113");
    all1000Digits.append("62229893423380308135336276614282806444486645238749");
    all1000Digits.append("30358907296290491560440772390713810515859307960866");
    all1000Digits.append("70172427121883998797908792274921901699720888093776");
    all1000Digits.append("65727333001053367881220235421809751254540594752243");
    all1000Digits.append("52584907711670556013604839586446706324415722155397");
    all1000Digits.append("53697817977846174064955149290862569321978468622482");
    all1000Digits.append("83972241375657056057490261407972968652414535100474");
    all1000Digits.append("82166370484403199890008895243450658541227588666881");
    all1000Digits.append("16427171479924442928230863465674813919123162824586");
    all1000Digits.append("17866458359124566529476545682848912883142607690042");
    all1000Digits.append("24219022671055626321111109370544217506941658960408");
    all1000Digits.append("07198403850962455444362981230987879927244284909188");
    all1000Digits.append("84580156166097919133875499200524063689912560717606");
    all1000Digits.append("05886116467109405077541002256983155200055935729725");
    all1000Digits.append("71636269561882670428252483600823257530420752963450");

    vector<unsigned int> singleDigits;
    singleDigits.reserve(1000);

    transform (all1000Digits.begin(), all1000Digits.end(),
               back_inserter(singleDigits),
               CInt());

    unsigned int product, maxProduct(0);

    vector<unsigned int>::iterator iter;

    for(iter = singleDigits.begin(); iter < singleDigits.end() - 5; ++iter) {
        product = accumulate (iter, iter + 5, 1, multiplies<unsigned int>());
        maxProduct = max(product, maxProduct);
    }

    cout << "The maximum product of 5 consecutive digits of the string is: "
         << maxProduct << endl;
}
