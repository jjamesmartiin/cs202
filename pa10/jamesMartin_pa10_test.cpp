#include "Bag.h"
#include <iostream>

using namespace std;

void Bag_test() { 
    cout << endl << "BAG TEST" << endl;

    Bag bag;
    cout << "Bag size should be 0; bag.size() is: " << bag.size() << endl;    
}

void size_test() {
    cout << endl << "SIZE TEST" << endl;

    Bag bag;
    bag.insert(1);
    cout << "Bag size should be 1; bag.size() is: " << bag.size() << endl;
    for(int i = 1; i < bag.CAPACITY; i++) {
        bag.insert(i);
    }
    cout << "Bag size should be " << bag.CAPACITY << "; bag.size() is: " << bag.size() << endl;
}

void empty_test() {
    cout << endl << "EMPTY TEST" << endl;

    Bag bag;
    cout << "Bag should be empty; bag.empty() is: " << bag.empty() << endl;
}

void do_insert(Bag &bag) {
    bag.insert(0);
    bag.insert(1);
    bag.insert(2);
    bag.insert(3);
    bag.insert(4);
    
    bag.insert(10);
    bag.insert(11);
    bag.insert(12);
    bag.insert(13);
    bag.insert(14);
}

void insert_test() {
    cout << endl << "INSERT TEST" << endl;

    Bag bag;
    do_insert(bag);

    cout << "Bag size should be 10; bag size is: " << bag.size() << endl;
    cout << "Bag output should be {0,1,2,3,4,10,11,12,13,14}; bag output is: ";
    bag.write();
    cout << endl;
}

void erase_one_test() {
    cout << endl << "ERASE ONE TEST" << endl;
    Bag bag; 
    do_insert(bag);

    cout << "Bag size should be 10; bag size is: " << bag.size() << endl;
    cout << "Bag output should be {0,1,2,3,4,10,11,12,13,14}; bag output is: ";
    bag.write();
    cout << endl;
    bag.erase_one(10);
    cout << "Erasing 10; bag size should be 9; bag size is: " << bag.size() << endl;
    cout << "Bag output should be {0,1,2,3,4,11,12,13,14}; bag output is: ";
    bag.write();
    cout << endl;
}

void clear_test() {
    cout << endl << "CLEAR TEST" << endl;
    Bag bag;
    do_insert(bag);

    cout << "Bag size should be 10; bag size is: " << bag.size() << endl;
    cout << "Bag output should be {0,1,2,3,4,10,11,12,13,14}; bag output is: ";
    bag.write();
    cout << endl;

    bag.clear();
    cout << "Cleared bag; size() should be 0; size() is: " << bag.size() << endl; 
}

void count_test() { 
    cout << endl << "COUNT TEST" << endl;
    Bag bag;
    do_insert(bag);
    bag.insert(10);
    bag.insert(10);
    cout << "Counting # of 10's in bag; should be 3; count() is: " << bag.count(10) << endl;
}

void write_test() {
    cout << endl << "COUNT TEST" << endl;
    Bag bag;
    do_insert(bag);

    cout << "Output of bag should be: {0,1,2,3,4,10,11,12,13,14}";
    bag.write();
    cout << endl;
}

int main() {
    Bag_test();
    size_test();
    empty_test();
    insert_test();
    erase_one_test();
    clear_test();
    count_test();
    write_test();

    return 0;
}