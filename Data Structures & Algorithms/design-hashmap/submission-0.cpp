class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for (auto &item : m_data) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }
        m_data.emplace_back(std::pair<int, int>{key, value});
    }
    
    int get(int key) {
        for (const auto &item : m_data) {
            if (item.first == key) {
                return item.second;
            }
        }
         return -1;
    }
    
    void remove(int key) {
        for (std::size_t i = 0; i < m_data.size(); i++) {
            if (m_data[i].first == key) {
                m_data.erase(m_data.begin() + i);
                return;
            }
        }
    }

private:
    std::vector<std::pair<int, int>> m_data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */