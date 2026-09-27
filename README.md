HashTable

A simple hash table implemented in C++ using separate chaining for collision resolution.

Known limitations

    Fixed table size — no resizing/rehashing when the load factor grows.
  
    The hash function is a simple additive checksum, which is easy to reason about but collision-prone for longer or anagram-like keys (e.g. "abc" and "cba" hash identically).
  
    strcpy_s ties the code to MSVC/Windows; portability requires a small change.
