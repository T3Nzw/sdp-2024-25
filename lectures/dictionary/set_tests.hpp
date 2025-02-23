#include "doctest.h"
#include "set.hpp"
#include "associative_list.hpp"
#include "bst_dictionary.hpp"
#include "hash_table.hpp"

#define SETS Set<int, AssociativeList>, Set<int, BSTDictionary>, Set<int, HashTable>
#define ITERABLE_SETS Set<int, AssociativeList>, Set<int, HashTable>

TEST_CASE_TEMPLATE("Създаване на празно множество", Set, SETS) {
    Set set;
    CHECK(set.empty());
}

TEST_CASE_TEMPLATE("Добавяне на елемент в множество", Set, SETS) {
    Set set;
    CHECK(set.insert(42));
    CHECK(!set.empty());
}

TEST_CASE_TEMPLATE("Добавяне на елементи в множество", Set, SETS) {
    Set set;
    CHECK(set.insert(42));
    CHECK(!set.insert(42));
    CHECK(set.insert(1));
    CHECK(!set.insert(1));
    CHECK(set.insert(100));
    CHECK(!set.insert(100));
    CHECK(!set.empty());

    CHECK(set.contains(42));
    CHECK(set.contains(1));
    CHECK(set.contains(100));
}

TEST_CASE_TEMPLATE("Премахване на елементи от множество", Set, SETS) {
    Set set;
    CHECK(set.insert(42));
    CHECK(set.insert(1));
    CHECK(set.insert(100));

    CHECK(set.remove(42));
    CHECK(!set.remove(42));
    CHECK(set.remove(1));
    CHECK(!set.remove(1));
    CHECK(set.remove(100));
    CHECK(!set.remove(100));
    CHECK(set.empty());
}

TEST_CASE_TEMPLATE("Итериране на елементите на множество", Set, ITERABLE_SETS) {
    Set set;
    CHECK(set.insert(42));
    CHECK(set.insert(1));
    CHECK(set.insert(100));

    int sum = 0;
    for (int el : set)
        sum += el;
    CHECK(sum == 42 + 1 + 100);
}