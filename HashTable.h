#pragma once

class HashTable {
private:
    typedef unsigned char HashIndex;
    struct Node {
        char* key_;
        Node* next_;
        Node(const char*, Node*);
        ~Node();
    };
    int size_;
    Node** table_;

    void clear(Node*);
public:
    HashTable(int);

    HashTable(HashTable&) = delete;
    HashTable& operator=(HashTable&) = delete;
    HashTable(HashTable&&) = delete;
    HashTable& operator=(HashTable&&) = delete;
    
    ~HashTable();

    HashIndex hash(const char*);
    bool insert(const char*);
    bool remove(const char*);
    bool contains(const char*);
    void printSameHash(HashIndex);
    void print();
};