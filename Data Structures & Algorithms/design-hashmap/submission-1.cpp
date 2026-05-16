// Using fixed-size arrays
class MyHashMap {
public:
    MyHashMap() : m_data(1000000, -1) {
        
    }
    
    void put(int key, int value) {
        m_data[key] = value;
    }
    
    int get(int key) {
        return m_data[key];
    }
    
    void remove(int key) {
        m_data[key] = -1;
    }

private:
    std::vector<int> m_data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */