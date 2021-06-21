#include <cstdlib>
#include <ctime>
#include <iostream>

#include "OrderedSet.h"

int main() {
    using namespace std;
    
    OrderedSet    lottery;
    OrderedSet    powerball;
    ostringstream output;

    srand(static_cast<unsigned>(time(nullptr)));

    // pick five unique lottery numbers
    while (lottery.size() != 5) {
        lottery.insert(rand() % 69 + 1);  // [1..69]
    }

    // pick the powerball
    powerball.insert(rand() % 26 + 1);    // [1..26]

    // display results
    cout << "Tonight's winning lottery numbers are: ";
    lottery.write();
    powerball.write();
    cout << endl;

    return 0;
}