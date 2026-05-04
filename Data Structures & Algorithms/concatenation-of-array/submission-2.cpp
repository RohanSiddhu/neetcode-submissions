class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> ans;
        ans.reserve(n * 2);
        for (size_t i = 0; i < 2; i++) {
            for (const auto &num : nums) {
                ans.emplace_back(num);
            }
        }
        return ans;
    }
};