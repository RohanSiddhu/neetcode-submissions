// Insertion Sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (std::size_t j = 1; j < nums.size(); j++) {
            int key = nums[j];

            std::size_t i = j;
            while (i && nums[i - 1] > key) {
                --i;
                nums[i + 1] = nums[i];
            }

            nums[i] = key;
        }

        return nums;
    }
};