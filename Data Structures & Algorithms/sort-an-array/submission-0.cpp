// Bubble sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (std::size_t i = 0; i < nums.size(); i++) {
            for (std::size_t j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }

        return nums;
    }
};