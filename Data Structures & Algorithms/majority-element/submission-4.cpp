class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int count = 0;

        for (auto num : nums) {
            if (0 == count) {
                res = num;
            }

            count += (num == res) ? 1 : -1;
        }

        return res;
    }
};