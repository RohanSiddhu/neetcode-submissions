// Horizontal Scanning

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix{strs[0]};

        for (std::size_t i{0}; i < strs.size(); i++) {
            std::size_t j{0};

            while (j < std::min(prefix.length(), strs[i].length())) {
                if (prefix[j] != strs[i][j]) {
                    break;
                }
                ++j;
            }

            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};