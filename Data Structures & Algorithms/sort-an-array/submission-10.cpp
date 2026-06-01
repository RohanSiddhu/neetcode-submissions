class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }

        shellSort(nums);
        return nums;
    }

private:
    void shellSort(vector<int> &nums) {
        for (int gap = nums.size() / 2; gap >= 1; gap /= 2) {
            for (int i = gap; i < nums.size(); ++i) {
                int tmp = nums[i]; 
                int j = i - gap;
                while (j >= 0 && nums[j] > tmp) {
                    nums[j + gap] = nums[j];
                    j -= gap;
                }
                nums[j + gap] = tmp;
            }
        }
    }
};