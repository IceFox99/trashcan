class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long result = 0;
        for (int i = 0; i != nums.size() - 1; ++i) {
            auto beg = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            if (beg == nums.end()) continue;
            auto end = upper_bound(beg, nums.end(), upper - nums[i]);
            result += end - beg;
        }
        return result;
    }
};
