class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int size = nums.size();
        long p[size + 1];
        std::deque<int> d;
        int res = size + 1;

        p[0] = 0;
        d.push_back(0);

        for (int i = 1; i != size + 1; ++i) {
            p[i] = p[i - 1] + nums[i - 1];
            while (!d.empty() && p[i] <= p[d.back()])
                d.pop_back();
            while (!d.empty() && p[i] - p[d.front()] >= k) {
                res = std::min(res, i - d.front());
                d.pop_front();
            }
            d.push_back(i);
        }

        return res <= size ? res : -1;
    }
};
