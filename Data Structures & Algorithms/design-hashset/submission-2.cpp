class MyHashSet {
public:
    MyHashSet() :  m_data(1000000, false) {
        
    }
    
    void add(int key) {
        m_data[key] = true;
    }
    
    void remove(int key) {
        m_data[key] = false;
    }
    
    bool contains(int key) {
        return m_data[key];
    }

private:
    std::vector<bool> m_data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */