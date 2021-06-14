#include <iostream>
#include "Container.h"
using namespace std;

// Function prototypes
void get_ages(Container& container);
void check_ages(Container& container);

int main() {
    Container ages;

    get_ages(ages);
    // check_ages(ages);

    return EXIT_SUCCESS;
}

/// Prompt the user to enter the ages of family members. These ages are read
/// and placed in the container, stopping when the it is full or when the user
/// types a negative value (sentinel).
void get_ages(Container& container) {
    int age;
    cout << container.size() << ": container.size() " << Container::CAPACITY << ": container::CAPACITY" << endl;
    cout << "Enter ages of family members (negative value to exit):\n";
    while (container.size() < Container::CAPACITY && cin >> age && !(age < 0)) {
        container.insert(age);
    }

    if (container.size() == Container::CAPACITY) {
        cout << "I have run out of room! You have a large family!\n";
    }
}

/// Prompt the user to enter in the ages of family members, again. Each age is
/// removed from the container, stopping when the container is empty.
void check_ages(Container& container) {
    cout << "Enter those ages again (press <return> after each age):\n";

    while (!container.empty()) {
        int age;

        cout << "Enter a family member's age: ";
        cin >> age;

        if (container.contains(age)) {
            container.erase(age);
            cout << "Yes, I found that age and removed it.\n";
        } else {
            cout << "No, that age does not occur!\n";
        }
    }
}