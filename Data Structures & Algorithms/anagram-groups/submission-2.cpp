class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;

        for (std::size_t i = 0; i < strs.size(); i++) {
            std::string key(26, '\0');
            for (const char ch : strs[i]) {
                key[ch - 'a']++;
            }

            if (anagramMap.find(key) == anagramMap.end()) {
                anagramMap[key] = std::vector{strs[i]};
            } else {
                anagramMap[key].emplace_back(strs[i]);
            }
        }

        std::vector<std::vector<std::string>> ans;

        for (const auto &item : anagramMap) {
            ans.emplace_back(item.second);
        }

        return ans;
    }
};
