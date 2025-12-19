#include <iostream>
#include "lru_cache.h"

using namespace std;

int main() {
    LRUCache lru(2);

    lru.put(1, 10);
    lru.put(2, 20);

    cout << lru.get(1) << endl;

    lru.put(3, 30); 

    cout << lru.get(2) << endl;

    return 0;
}
