class BST {
public:
    BST() : m_root(nullptr) {}

    void add(int key) {
        m_root = m_insert(m_root, key);
    }

    void remove(int key) {
        m_root = m_delete(m_root, key);
    }

    bool contains(int key) {
        return m_search(m_root, key);
    }
private:
    struct TreeNode {
        int key;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int key) : key(key), left(nullptr), right(nullptr) {}
    };

    TreeNode* m_insert(TreeNode *root, int key) {
        if (!root) {
            return new TreeNode(key);
        }

        if (key < root->key) {
            root->left = m_insert(root->left, key);
        } else if (key > root->key) {
            root->right = m_insert(root->right, key);
        }

        return root;
    }

    TreeNode* m_delete(TreeNode *root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key < root->key) {
            root->left = m_delete(root->left, key);
        } else if (key > root->key) {
            root->right = m_delete(root->right, key);
        } else {
            if (!root->left) {
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            }
            if (!root->right) {
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }

            TreeNode *tmp = m_minValueNode(root->right);
            root->key = tmp->key;
            root->right = m_delete(root->right, tmp->key);
        }
        return root;
    }

    TreeNode* m_minValueNode(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }

        return root;
    }

    bool m_search(TreeNode *root, int key) {
        if (!root) {
            return false;
        }

        if (key < root->key) {
            return m_search(root->left, key);
        } else if (key > root->key) {
            return m_search(root->right, key);
        } else {
            return true;
        }
    }

    TreeNode *m_root;
};

class MyHashSet {
public:
    MyHashSet(): m_buckets(m_size) {
        
    }
    
    void add(int key) {
        if (!contains(key)) {
            m_buckets[m_hash(key)].add(key);
        }
    }
    
    void remove(int key) {
        m_buckets[m_hash(key)].remove(key);
    }
    
    bool contains(int key) {
        return m_buckets[m_hash(key)].contains(key);
    }

private:
    const int m_size = 10000;
    std::vector<BST> m_buckets;

    int m_hash(int key) {
        return key % m_size;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */