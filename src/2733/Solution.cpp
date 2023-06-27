// My version
class Solution {
public:
	int findNonMinOrMax(vector<int>& nums) {
		if (nums.size() <= 2)
			return -1;

		int minimum = min(nums[0], nums[1]);
		int maximum = max(nums[0], nums[1]);
		if (nums[2] > maximum)
			return maximum;
		if (nums[2] < minimum)
			return minimum;
		return nums[2];
	}
};
