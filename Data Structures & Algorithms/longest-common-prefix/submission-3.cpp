// Vertical Scanning

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::size_t j{0};

        for (std::size_t i{0}; i < strs[0].length(); i++) {
            for (const auto & str : strs) {
                if (str.length() < j || str[j] != strs[0][j]) {
                    return strs[0].substr(0, j);
                }
            }
            ++j;
        }

        return strs[0].substr(0, j);
    }
};