#include <iostream>
#include "HashTable.h"

void testInsertAndContains() {
    std::cout << "=== Test 1: Insert & Contains ===\n";
    HashTable ht(10);

    ht.insert("apple");
    ht.insert("banana");
    ht.insert("orange");

    std::cout << "Contains 'apple'? " << (ht.contains("apple") ? "Yes" : "No") << "\n";
    std::cout << "Contains 'pear'? " << (ht.contains("pear") ? "Yes" : "No") << "\n";
    std::cout << "Insert duplicate 'apple'? " << (ht.insert("apple") ? "Success" : "Failed (expected)") << "\n";
}

void testRemove() {
    std::cout << "\n=== Test 2: Remove ===\n";
    HashTable ht(10);

    ht.insert("apple");
    ht.insert("banana");

    std::cout << "Remove 'banana'? " << (ht.remove("banana") ? "Success" : "Failed") << "\n";
    std::cout << "Contains 'banana' after removal? " << (ht.contains("banana") ? "Yes" : "No") << "\n";
    std::cout << "Remove non-existent 'pear'? " << (ht.remove("pear") ? "Success" : "Failed (expected)") << "\n";
}

void testCollisions() {
    std::cout << "\n=== Test 3: Collisions ===\n";
    HashTable ht(5);

    ht.insert("abc");
    ht.insert("cba");
    ht.insert("xyz");

    std::cout << "Same hash chain for 'abc' and 'cba':\n";
    ht.printSameHash(ht.hash("abc"));

    ht.print();
}

void testEdgeCases() {
    std::cout << "\n=== Test 4: Edge Cases ===\n";
    HashTable ht(3);

    std::cout << "Empty table:\n";
    ht.print();

    std::cout << "Print invalid hash 100:\n";
    ht.printSameHash(100);

    std::cout << ht.insert("") << '\n';
    std::cout << "Contains empty string? " << (ht.contains("") ? "Yes" : "No") << "\n";
}


int main() {
    testInsertAndContains();
    testRemove();
    testCollisions();
    testEdgeCases();
    return 0;
}