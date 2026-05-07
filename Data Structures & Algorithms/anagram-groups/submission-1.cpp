class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::size_t>> anagramMap;

        for (std::size_t i = 0; i < strs.size(); i++) {
            std::string key(26, '\0');
            for (const char ch : strs[i]) {
                key[ch - 'a']++;
            }

            if (anagramMap.find(key) == anagramMap.end()) {
                anagramMap[key] = std::vector{i};
            } else {
                anagramMap[key].emplace_back(i);
            }
        }

        std::vector<std::vector<std::string>> ans;

        for (const auto &item : anagramMap) {
            std::vector<std::string> strVec;
            for (const auto i : item.second) {
                strVec.emplace_back(strs[i]);
            }
            ans.emplace_back(strVec);
        }

        return ans;
    }
};
