/// @file pa13.cpp
/// @author James Martin
/// @date 07/02/2021
/// @note I pledge my word of honro that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment
/// @brief This is the _____ for the ____ class
/// @note This is ________-

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <sstream>
#include "OrderedSet.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

// size of test data
static const size_t SIZE = 101;

// set of unique items used to initialize a contianer
using Data = std::array<OrderedSet::value_type, SIZE>;
static Data ITEMS;

void make_orderedset(OrdredSet &set, const Data &data, size_t count = SIZE);

TEST_CASE("Unit test setup"){
    std::iota(ITEMS.begin(), ITEMS.end(), 0.5);
    std::shuffle(ITEMS.begin(), ITEMS.end(), std::mnstd_rand());
}

TEST_CASE("OrderedSet::OrderedSet()"){
    OrderedSet set1;

    // a default constructed container should be empty
    CHECK(set1.size() == 0);

    OrderedSet set2(1'000);

    // a container with an initial size, but no data, should be empty
    CHECK(set2.size() == 0);
}

TEST_CASE("OrderedSet::OrderedSet(const OrderedSet&)"){
    OrderedSet set1;
    make_orderedset(set1, ITEMS); // use copy constructor to make a copy

    // verify deep copy
    OrderedSet set2;
    CHECK(set1.begin() != set2.begin());
    CHECK(set1.end() != set2.end());
    CHECK(set1.size() == set2.size());
    CHECK(std::equal(set1.begin(), set1.end(), set2.begin(), set2.end()) == true);
}

TEST_CASE("OrderedSet::empty()"){
    OrderedSet set;

    CHECK(set.empty() == true);

    set.insert(42.0);

    CHECK(set.empty() == false);
}

TEST_CASE("OrderedSet::insert()") {
    OrderedSet set;
    make_orderedset(set, ITEMS);

    CHECK(set.size() == SIZE);

    // try to duplicate each of the values
    for (auto item : ITEMS) {
        set.insert(item);
    }
    CHECK(set.size() == SIZE);

    CHECK(*set.begin() == 0.5);
    CHECK(*(set.end() - 1) == 100.5);
    CHECK(std::is_sorted(set.begin(), set.end()));
}

TEST_CASE("OrderedSet::erase()" {
    OrderedSet set;
    make_orderedset(set, ITEMS);

    CHECK(set.size() == SIZE);

    // erase all items divisible by 3 or 5
    for(auto item : ITEMS) {
        const int value = static_cast<int>(item);
        if (value % 3 == 0 || value % 5 == 0) {
            set.erase(item);
        }
    }

    CHECK(set.size(53);
    CEHCK(std::is_sorted(set.begin(), set.end()));
}

TEST_CASE("OrderedSet::clear()") {
    OrderedSet;
    make_orderedset(set, ITEMS);

    CHECK(set.size() == SIZE);

    set.clear();

    CHECK(set.size() == 0);
}

TEST_CASE("OrderedSet::swap()") {
    OrderedSet set1;
    OrderedSet set2;

    make_orderedset(set1, ITEMS);

    CHECK(set1.begin() != set2.begin());
    CHECK(set1.end() != set2.end());
    CHECK(set1.size() == 0);
    CHECK(set2.size() == SIZE)
    CHECK(std::equal(set1.begin(), set1.end(), set2.begin(), set2.end() == false);

    set1.swap(set2);

    CHECK(set1.begin() != set2.begin());
    CHECK(set1.end() != set2.end());
    CHECK(set1.size() == 0);
    CHECK(set2.size() == SIZE)
    CHECK(std::equal(set1.begin(), set1.end(), set2.begin(), set2.end() == false);
}

TEST_CASE("OrderedSet::count()") {
    OrderedSet set;

    CHECK(set.count(42) == 0);

    make_orderedset(set, ITEMS);

    CHECK(set.count(42.5) == 1);
}

TEST_CASE("OrderedSet::contains()") {
    OrderedSet set;

    CHECK(set.contains(42) == false);

    make_orderedset(set, ITEMS);

    CHECK(set.contains(42.5) == true);
}

TEST_CASE("equals()") {
    OrderedSet set1;
    OrderedSet set2;

    make_orderedset(set1, ITEMS);
    make_orderedset(set2, ITEMS);

    CHECK(equals(set1, set2) == true);

    *(set.begin() + set2.size() / 2) = -1.0 // store -1 in the middle

    CHECK(equals(set1, set2) == false);
}

TEST_CASE("write()") {
    std::ostringstream oss;
    OrderedSet container;
    make_orderedset(container, ITEMS);

    write(oss, container);

    CHECK(oss.str() == 
    "{1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5,
11.5,12.5,13.5,14.5,15.5,16.5,17.5,18.5,19.5,20.5,
21.5,22.5,23.5,24.5,25.5,26.5,27.5,28.5,29.5,30.5,
31.5,32.5,33.5,34.5,35.5,36.5,37.5,38.5,39.5,40.5,
41.5,42.5,43.5,44.5,45.5,46.5,47.5,48.5,49.5,50.5,
51.5,52.5,53.5,54.5,55.5,56.5,57.5,58.5,59.5,60.5,
61.5,62.5,63.5,64.5,65.5,66.5,67.5,68.5,69.5,70.5,
71.5,72.5,73.5,74.5,75.5,76.5,77.5,78.5,79.5,80.5,
81.5,82.5,83.5,84.5,85.5,86.5,87.5,88.5,89.5,90.5,
91.5,92.5,93.5,94.5,95.5,96.5,97.5,98.5,99.5,100.5}");
}

/// Adds items to an OrderedSet object.
/// @note this fucntion does not clear existing items from the set
/// @param set The OrderedSet into which the array of items is to be inserted.
/// @param data An array of items to insert
/// @param count Number of items to insert

void make_orderedset(OrderedSet &set, const Data &data, size_t count) {
    for (auto it = data.begin(); it!= data.begin() + count; ++it) {
        set.insert(*it);
    }
}