#include <iostream>
#include <cstring>
#include "HashTable.h"

typedef unsigned char HashIndex;

HashTable::Node::Node(const char* key, Node* next = nullptr) {
    key_ = new char[strlen(key) + 1];
    strcpy_s(key_, strlen(key) + 1, key);
    next_ = next;
}

HashTable::Node::~Node() {
    delete[] key_;
}

HashTable::HashTable(int size) : size_(size) {
    table_ = new Node*[size]();
}

HashTable::~HashTable() {
    for (int i = 0; i < size_; i++) {
        clear(table_[i]);
    }
    delete[] table_;
}

void HashTable::clear(Node* node) {
    if (!node) return;
    clear(node->next_);
    delete node;
}

HashIndex HashTable::hash(const char* str) {
    HashIndex h = 0;
    while (*str) {
        h += *str++;
    }
    return (int)h % size_;
}

bool HashTable::insert(const char* key) {
    if (!key || contains(key) || strlen(key) == 0) return 0;
    Node* newNode = new Node(key);
    HashIndex index = hash(key);
    newNode->next_ = table_[index];
    table_[index] = newNode;
    return 1;
}

bool HashTable::remove(const char* key) {
    HashIndex index = hash(key);
    Node* node = table_[index];
    Node* prev = nullptr;
    while (node) {
        if (strcmp(node->key_, key) == 0) {
            if (prev) {
                prev->next_ = node->next_;
            }
            else {
                table_[index] = node->next_;
            }
            delete node;
            return 1;
        }
        prev = node;
        node = node->next_;
    }
    return 0;
}

bool HashTable::contains(const char* key) {
    HashIndex index = hash(key);
    Node* node = table_[index];
    while (node) {
        if (strcmp(node->key_, key) == 0) return 1;
        node = node->next_;
    }
    return 0;
}

void HashTable::printSameHash(HashIndex index) {
    if ((int)index >= size_) {
        std::cout << "Invalid hash value (" << (int)index << ")\n";
        return;
    }
    std::cout << "[" << (int)index << "]: ";
    Node* node = table_[index];
    if (!node) {
        std::cout << "empty\n";
    }
    else {        
        while (node) {
            std::cout << node->key_ << ' ';
            node = node->next_;
        }
        std::cout << '\n';
    }
}

void HashTable::print() {
    for (int i = 0; i < size_; i++) {
        Node* node = table_[i];
        if (node) {
            std::cout << '[' << i << "]: ";
            while (node) {
                std::cout << node->key_ << ' ';
                node = node->next_;
            }
            std::cout << '\n';
        }
        else 
            continue;
    }
}
