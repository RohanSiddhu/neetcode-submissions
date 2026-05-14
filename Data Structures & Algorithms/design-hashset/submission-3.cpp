class MyHashSet {
public:
    MyHashSet() {
        m_bucketArr.resize(10000);
        for (auto &bucket : m_bucketArr) {
            bucket = new ListNode(0);
        }
    }
    
    void add(int key) {
        ListNode *current = m_bucketArr[m_hash(key)];

        while (current->next) {
            if (current->next->key == key) {
                return;
            }
            current = current->next;
        }
        current->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode * current = m_bucketArr[m_hash(key)];

        while (current->next) {
            if (current->next->key == key) {
                ListNode *tmp = current->next;
                current->next = current->next->next;
                delete tmp;
                return;
            }
            current = current->next;
        }
    }
    
    bool contains(int key) {
        ListNode *current = m_bucketArr[m_hash(key)];
        while (current->next) {
            if (current->next->key == key) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

private:
    struct ListNode {
        int key;
        ListNode *next;

        ListNode(int key): key(key), next(nullptr) {}
    };

    std::vector<ListNode*> m_bucketArr;

    int m_hash(int key) {
        return key % 10'000;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */