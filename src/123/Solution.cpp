// My version
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = prices[0], last = left, right, min = left, profit = 0;
        bool incr = false;
        vector<pair<int, int>> ext;
        vector<int> profit_f, profit_b;

        // forwards
        for (int i = 1; i != prices.size(); ++i) {
            if (prices[i] >= last) {
                right = prices[i];
                incr = true;
                profit = std::max(profit, prices[i] - min);
            }
            else {
                min = std::min(min, prices[i]);
                if (incr) {
                    ext.push_back(make_pair(left, right));
                    profit_f.push_back(profit);
                }
                left = prices[i];
                incr = false;
            }
            last = prices[i];
        }
        if (incr) {
            ext.push_back(make_pair(left, right));
            profit_f.push_back(profit);
        }

        if (ext.empty()) return 0;

        // backwards
        int max = 0; profit = 0;
        for (int i = ext.size() - 1; i >= 0; --i) {
            max = std::max(ext[i].second, max);
            profit = std::max(profit, max - ext[i].first);
            profit_b.push_back(profit);
        }

        // dynamic programming
        int res = 0;
        for (int i = 0; i != ext.size() - 1; ++i)
            res = std::max(profit_f[i] + profit_b[ext.size() - i - 2], res);
        res = std::max(res, profit_f.back());

        return res;
    }
};

// Community version
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};
