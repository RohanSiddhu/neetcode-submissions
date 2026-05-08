class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        int k = nums.size() - 1;

        while (j <= k) {
            if (nums[k] == val) {
                --k;
            } else if (nums[j] == val) {
                int tmp = nums[j];
                nums[j] = nums[k];
                nums[k] = tmp;
            } else {
                ++j;
            }
        }

        return ++k;
    }
};