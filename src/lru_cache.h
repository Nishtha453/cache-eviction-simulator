#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v);
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void removeNode(Node* node);
    void insertAtFront(Node* node);

public:
    LRUCache(int cap);
    int get(int key);
    void put(int key, int value);
};

#endif
