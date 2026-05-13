// Brute Force

class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (std::find(m_data.cbegin(), m_data.cend(), key) == m_data.end()) {
            m_data.emplace_back(key);
        }
    }
    
    void remove(int key) {
        auto it = std::find(m_data.cbegin(), m_data.cend(), key);
        if (it != m_data.end()) {
            m_data.erase(it);
        }
    }
    
    bool contains(int key) {
        return std::find(m_data.cbegin(), m_data.cend(), key) != m_data.end();
    }

private:
    std::vector<int> m_data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */