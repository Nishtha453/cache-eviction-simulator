#include "lru_cache.h"

Node::Node(int k, int v) {
    key = k;
    value = v;
    prev = nullptr;
    next = nullptr;
}
LRUCache::LRUCache(int cap) {
    capacity = cap;

    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
}
void LRUCache::removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
void LRUCache::insertAtFront(Node* node) {
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}
int LRUCache::get(int key) {
    if (cache.find(key) == cache.end()) {
        return -1; // cache miss
    }

    Node* node = cache[key];

    removeNode(node);
    insertAtFront(node);

    return node->value;
}
void LRUCache::put(int key, int value) {
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;

        removeNode(node);
        insertAtFront(node);
    } else {
        if (cache.size() == capacity) {
            Node* lru = tail->prev;

            cache.erase(lru->key);
            removeNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insertAtFront(newNode);
    }
}
