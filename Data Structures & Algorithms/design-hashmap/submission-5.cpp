class MyHashMap {
public:
    MyHashMap() : m_buckets() {
        m_buckets.resize(10000);
        for (auto &bucket: m_buckets) {
            bucket = new ListNode();
        }
    }
    
    void put(int key, int value) {
        ListNode *node = m_buckets[m_hash(key)];

        while (node->next) {
            if (node->next->key == key) {
                node->next->val = value;
                return;
            }
            node = node->next;
        }

        node->next = new ListNode(key, value);
    }
    
    int get(int key) {
        ListNode *node = m_buckets[m_hash(key)];

        while (node->next) {
            if (node->next->key == key) {
                return node->next->val;
            }
            node = node->next;
        }

        return -1;
    }
    
    void remove(int key) {
        ListNode *node = m_buckets[m_hash(key)];

        while (node->next) {
            if (node->next->key == key) {
                ListNode *tmp = node->next;
                node->next = node->next->next;
                delete tmp;
                return;
            }
            node = node->next;
        }
    }

private:
    struct ListNode {
        int key;
        int val;
        ListNode *next;

        ListNode(int key = -1, int val = -1, ListNode *next = nullptr): key(key), val(val), next(next) {}
    };

    std::vector<ListNode*> m_buckets;

    int m_hash(int key) {
        return key % m_buckets.size();
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */