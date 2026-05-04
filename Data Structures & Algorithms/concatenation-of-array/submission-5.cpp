class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto n = nums.size();
        nums.reserve(2 * n);
        for (size_t i = 0; i < n; ++i) {
            nums.emplace_back(nums[i]);
        }
        return nums;
    }
};