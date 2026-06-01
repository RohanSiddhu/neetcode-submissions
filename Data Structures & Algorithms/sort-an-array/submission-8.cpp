void counting_sort(vector<int> &nums) {
    unordered_map<int, int> count;

    int minVal = nums[0];
    int maxVal = nums[0];

    for (const auto val : nums) {
        ++count[val];
        if (val < minVal) {
            minVal = val;
        }
        if (val > maxVal) {
            maxVal = val;
        }
    }

    int i = 0;
    for (int val = minVal; val <= maxVal; ++val) {
        while (count[val] > 0) {
            nums[i] = val;
            ++i;
            --count[val];
        }
    }
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        counting_sort(nums);

        return nums;
    }
};