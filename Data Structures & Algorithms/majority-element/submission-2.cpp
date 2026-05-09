class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freqMap;
        int ans = 0;
        int maxCount = 0;

        for (auto num : nums) {
            if (freqMap.find(num) == freqMap.end()) {
                freqMap[num] = 1;
            } else {
                freqMap[num]++;
            }
            if (freqMap[num] > maxCount) {
                ans = num;
                maxCount = freqMap[num];
            }
        }

        return ans;
    }
};