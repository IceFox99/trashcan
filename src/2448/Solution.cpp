// My version
class Solution {
public:
	long long calCost(vector<int>& nums, vector<int>& cost, int num) {
		long long C = 0;
		for (int i = 0; i != nums.size(); ++i) 
			C += (long long)abs(nums[i] - num) * cost[i];
		return C;
	}

	long long minCost(vector<int>& nums, vector<int>& cost) {
	    set<int> s;
		for (int i = 0; i != nums.size(); ++i)
			s.insert(nums[i]);

		int low = 0;
		int high = s.size() - 1;
		long long leftC = calCost(nums, cost, *next(s.begin(), low));
		long long rightC = calCost(nums, cost, *next(s.begin(), high));
		long long minimum = min(leftC, rightC);

		while (high - low > 2) {
			int dist = (high - low) / 3;
			leftC = calCost(nums, cost, *next(s.begin(), low + dist));
			rightC = calCost(nums, cost, *next(s.begin(), high - dist));
			minimum = min(minimum, min(leftC, rightC));
			if (leftC < rightC)
				high -= dist;
			else if (leftC > rightC)
				low += dist;
			else {
				low += dist;
				high -= dist;
			}
		}

		for (int i = low; i != high + 1; ++i)
			minimum = min(minimum, calCost(nums, cost, *next(s.begin(), i)));

		return minimum;
	}
};

// Community version
class Solution {
    struct S { int num, cost; bool operator<(S const& b) { return this->num < b.num; } }
    static inline data[100000];
    
    public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
    
    long long minCost(vector<int> const& nums, vector<int>& costs) { // weigted median
        int const n = size(nums);
        for(int i{0}; i < n; ++i) {
            data[i] = {nums[i], costs[i]}; // init
        }
        sort(data, n + data); // 123
        int i{0}, j{n-1};
        long ret{0}, cnt{0};
        while(i < j) {
            if(data[i].cost < data[j].cost) {
                data[j].cost -= data[i].cost;
                cnt += data[i].cost;
                ret += cnt * (data[i+1].num - data[i].num);
                ++i;
            }
            else {
                data[i].cost -= data[j].cost;
                cnt += data[j].cost;
                ret += cnt * (data[j].num - data[j-1].num);
                --j;
            }
        }
        return ret;
    }
};
