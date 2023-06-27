// My version
class Solution {	
public:
	int singleNumber(vector<int>& nums) {
		map<int, bool> m;
		for (int i : nums) {
			if (m.find(i) == m.end())
				m[i] = true;
			else
				m[i] = false;
		}

		for (auto it = m.begin(); it != m.end(); ++it) {
			if (it->second)
				return it->first;
		}

		throw invalid_argument("Illegal inputs.");
	}
};

// Community version
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (auto i : nums)
			result ^= i;
		return result;
	}
};
