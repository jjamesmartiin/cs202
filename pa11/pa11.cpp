#include <cstdlib>
#include <ctime>
#include <iostream>

#include "OrderedSet.h"

int main() {
    using namespace std;
    
    OrderedSet    lottery;
    OrderedSet    powerball;
    // ostringstream output; 
    //  ^^ was causing errors when compiling: "Incomplete type"

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "pick five unique lottery numbers" << endl;
    while (lottery.size() != 5)
    {
        lottery.insert(rand() % 69 + 1);  // [1..69]
    }

    cout << "pick the powerball" << endl;
    powerball.insert(rand() % 26 + 1); // [1..26]

    cout << "display results" << endl;
    cout << "Tonight's winning lottery numbers are: ";
    lottery.write();
    powerball.write();
    cout << endl;

    return 0;
}