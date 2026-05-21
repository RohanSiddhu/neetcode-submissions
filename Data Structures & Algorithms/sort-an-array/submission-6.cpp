// Merge Sort

void merge(vector<int> &nums, std::size_t low, std::size_t mid, std::size_t high) {
    const std::size_t N1 = mid - low + 1;
    const std::size_t N2 = high - mid;
    
    vector<int> lVec;
    lVec.reserve(N1);
    vector<int> rVec;
    rVec.reserve(N2);

    for (std::size_t i = low; i <= mid; i++) {
        lVec.emplace_back(nums[i]);
    }
    for (std::size_t i = mid + 1; i <= high; i++) {
        rVec.emplace_back(nums[i]);
    }

    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t k = low;

    while (i < N1 && j < N2) {
        if (lVec[i] <= rVec[j]) {
            nums[low] = lVec[i];
            ++i;
        } else {
            nums[low] = rVec[j];
            ++j;
        }
        ++low;
    }

    while (i < N1) {
        nums[low] = lVec[i];
        ++low;
        ++i;
    }

    while (j < N2) {
        nums[low] = rVec[j];
        ++low;
        ++j;
    }
}

void merge_sort(vector<int> &nums, std::size_t low, std::size_t high) {
    if (low < high) {
        std::size_t mid = (low + high) / 2;

        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);

        return nums;
    }
};