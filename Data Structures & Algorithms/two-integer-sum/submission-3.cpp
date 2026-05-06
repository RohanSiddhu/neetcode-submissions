class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pVec;

        for (int i = 0; i < nums.size(); i++) {
            pVec.emplace_back(nums[i], i);
        }

        sort(pVec.begin(), pVec.end());

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int sum = pVec[i].first + pVec[j].first;
            if (sum == target) {
                return vector<int>{
                    min(pVec[i].second, pVec[j].second),
                    max(pVec[i].second, pVec[j].second),
                };
            }
            (sum < target) ? ++i : --j;
        }
    }
};
