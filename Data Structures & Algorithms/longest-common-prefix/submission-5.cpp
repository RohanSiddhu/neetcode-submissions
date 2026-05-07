// Sorting

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (1 == strs.size()) {
            return strs[0];
        }

        sort(strs.begin(), strs.end());

        for (std::size_t i{0}; i < min(strs[0].length(), strs.back().length()); i++) {
            if (strs[0][i] != strs.back()[i]) {
                return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }
};