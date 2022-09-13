#include <iostream>
#include "Bag.h"
using namespace std;

// Function prototypes
void get_ages(Bag& bag);
void check_ages(Bag& bag);

int main() {
    Bag ages;

    get_ages(ages);
    check_ages(ages);

    return EXIT_SUCCESS;
}

/// Prompt the user to enter the ages of family members. These ages are read
/// and placed in the bag, stopping when the it is full or when the user
/// types a negative value (sentinel).
void get_ages(Bag& bag) {
    int age;

    cout << "Enter ages of family members (negative value to exit):\n";
    while (bag.size() < Bag::CAPACITY && cin >> age && !(age < 0)) {
        bag.insert(age);
    }

    if (bag.size() == Bag::CAPACITY) {
        cout << "I have run out of room! You have a large family!\n";
    }
}

/// Prompt the user to enter in the ages of family members, again. Each age is
/// removed from the bag, stopping when the bag is empty.
void check_ages(Bag& bag) {
    cout << "Enter those ages again (press <return> after each age):\n";

    while (!bag.empty()) {
        int age;

        cout << "Enter a family member's age: ";
        cin >> age;

        if (bag.erase_one(age)) {
            cout << "Yes, I found that age and removed it.\n";
        } else {
            cout << "No, that age does not occur!\n";
        }
    }
}