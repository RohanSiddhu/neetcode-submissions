// Trie

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        m_root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode *node = m_root;

        for (char ch : word) {
            if (node->children.find(ch) == node-> children.end()) {
                node->children[ch] = new TrieNode();
            }

            node = node->children[ch];
        }
    }

    int lcp(const string &word, int prefixLen) {
        TrieNode *node = m_root;
         
         int i = 0;
         while (i < std::min((int)word.length(), prefixLen)) {
            if (node->children.find(word[i]) == node->children.end()) {
                return i;
            }

            node = node->children[word[i]];
            ++i;
         }

         return std::min((int)word.length(), prefixLen);
    }

private:
    TrieNode *m_root;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        int mini = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[mini].size() > strs[i].size()) {
                mini = i;
            }
        }

        Trie trie;
        trie.insert(strs[mini]);
        int prefixLen = strs[mini].length();

        for (int i = 0; i < strs.size(); i++) {
            prefixLen = trie.lcp(strs[i], prefixLen);
        }

        return strs[0].substr(0, prefixLen);
    }
};