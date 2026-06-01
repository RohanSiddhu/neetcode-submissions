class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> negatives;
        vector<int> positives;

        for (const auto num : nums) {
            if (num < 0) {
                negatives.emplace_back(-num);
            } else {
                positives.emplace_back(num);
            }
        }

        if (!negatives.empty()) {
            radix_sort(negatives);
            std::reverse(negatives.begin(), negatives.end());
        }

        if (!positives.empty()) {
            radix_sort(positives);
        }

        int i = 0;
        for (const auto num : negatives) {
            nums[i++] = -num;
        }
        for (const auto num : positives) {
            nums[i++] = num;
        }

        return nums;
    }

    void radix_sort(vector<int> &nums) {
        int max = *std::max_element(nums.begin(), nums.end());
        int div = 1;

        while (max / div > 0) {
            counting_sort(nums, div);
            div *= 10;
        }
    }

    void counting_sort(vector<int> &nums, int div) {
        vector<int> count(10, 0);

        for (const auto num : nums) {
            ++count[(num / div) % 10];
        }
        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int idx = (nums[i] / div) % 10;
            res[--count[idx]] = nums[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = res[i];
        }
    }
};