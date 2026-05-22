// Heap Sort

void heapify(vector<int> &nums, std::size_t n, std::size_t i) {
    std::size_t l = (i << 1) + 1;
    std::size_t r = (i << 1) + 2;
    std::size_t maxNode = i;

    if (l < n && nums[l] > nums[maxNode]) {
        maxNode = l;
    }

    if (r < n && nums[r] > nums[maxNode]) {
        maxNode = r;
    }

    if (maxNode != i) {
        std::swap(nums[i], nums[maxNode]);
        heapify(nums, n, maxNode);
    }
}

void heap_sort(vector<int> &nums) {
    for (std::size_t i = nums.size() / 2; i > 0;) {
        --i;
        heapify(nums, nums.size(), i);
    }

    for (std::size_t i = nums.size(); i > 0;) {
        --i;
        std::swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums);
        return nums;
    }
};