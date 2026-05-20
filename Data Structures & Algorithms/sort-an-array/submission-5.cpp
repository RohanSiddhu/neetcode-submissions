// Quick Sort
// Pivot Selection: First Element
// Partition Algorithm: Hoare's Partition Algorithm

std::size_t partition(std::vector<int> &nums, std::size_t low, std::size_t high) {
    int pivot = nums[low];
    std::size_t i = low;
    std::size_t j = high;

    while (i < j) {
        while(i < j && nums[i] <= pivot) {
            ++i;
        }

        do {
            --j;
        } while (j > 0 && nums[j] > pivot);

        if (i < j) {
            std::swap(nums[i], nums[j]);
        }
    }

    std::swap(nums[low], nums[j]);

    return j;
}

void quick_sort(std::vector<int> &nums, std::size_t low, std::size_t high) {
    if (low < high) {
        std::size_t partPoint = partition(nums, low, high);
        quick_sort(nums, low, partPoint);
        quick_sort(nums, partPoint + 1, high);
    }
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size());

        return nums;
    }
};