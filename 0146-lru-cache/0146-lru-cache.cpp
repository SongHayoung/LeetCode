struct Node {
    int key, value;
    Node* prev, *next;
    Node(int key, int val) : key(key), value(val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    int cap;
    void promote(int key) {
        Node* node = mp[key];
        if(tail->key == key) {
            tail = tail->prev;
        }
        if(node->next) node->next->prev = node->prev;
        if(node->prev) node->prev->next = node->next;
        
        node->next = node->prev = nullptr;
        
        node->next = head->next;
        if(node->next) node->next->prev = node;
        head->next = node;
        node->prev = head;
        
        if(mp.size() > cap) {
            tail = tail->prev;
            mp.erase(tail->next->key);
            tail->next = nullptr;
        }
        
        if(tail->next) {
            tail = tail->next;
        }
    }
public:
    LRUCache(int capacity): cap(capacity) {
        head = new Node(-1, -1);
        tail = head;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;
        int res = mp[key]->value;
        promote(key);
        return res;
    }

    void put(int key, int value) {
        if(mp.count(key)) {
            mp[key]->value = value;
        } else mp[key] = new Node(key,value);
        promote(key);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */