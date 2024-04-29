// My version
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (const auto i : nums)
            k ^= i;
        int res = 0;
        while (k) {
            res += k & 1;
            k >>= 1;
        }
        return res;
    }
};
