class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int result = INT_MAX;
        int bits[32] = {};
        int val = 0, beg = 0;
        for (int i = 0; i != nums.size(); ++i) {
            int num = nums[i];
            if (num >= k) return 1;
            val |= num;
            for (int bit = 0; num; ++bit) {
                bits[bit] += (num & 1);
                num >>= 1;
            }
            while (val >= k && beg < nums.size()) {
                result = min(result, i - beg + 1);
                num = nums[beg];
                ++beg;
                for (int bit = 0; num; ++bit) {
                    bits[bit] -= (num & 1);
                    if (bits[bit] == 0)
                        val &= ~(1 << bit);
                    num >>= 1;
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
