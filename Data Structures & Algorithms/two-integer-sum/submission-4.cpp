class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nMap;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            auto val = nMap.find(diff);
            if (val != nMap.end()) {
                return std::vector<int>{std::min(val->second, i), std::max(val->second, i)};
            }
            nMap[nums[i]] = i;
        }
    }
};
