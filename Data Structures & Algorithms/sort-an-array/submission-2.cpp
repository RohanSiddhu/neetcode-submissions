// Selection Sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size() - 1;
        for (std::size_t i = 0; i < n; i++) {
            int min = i;
            for (std::size_t j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            int tmp = nums[i];
            nums[i] = nums[min];
            nums[min] = tmp;
        }

        return nums;
    }
};