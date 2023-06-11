// MY version
class Solution {
public:
    Solution(vector<int>& nums) :
        nums(nums) {}
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        int size = nums.size();

        vector<int> numsCopy(nums);
        vector<int> shuff;
        shuff.reserve(size);

        for (int i = size; i != 0; --i) {
            int randIndex = rand() % i;
            shuff.push_back(numsCopy[randIndex]);
            numsCopy.erase(numsCopy.begin() + randIndex);
        }

        return shuff;
    }
private:
    const vector<int>& nums;
};

// Community version
class Solution {
public:
    Solution(const vector<int>& nums) : nums(nums), arr(nums), seed(random_device{}()) {}

    vector<int> reset() {
		arr = nums;
		return arr;
	}

    vector<int> shuffle() {
        for (int i = size(arr) - 1; i > 0; --i) {
            auto idx = uniform_int_distribution<int>(0, i)(seed);
            swap(arr[i], arr[idx]);
        }
        return arr;
    }
private:
    vector<int> arr, nums;
    default_random_engine seed;
};

// Fisher-Yates shuffle algorithm
class Solution {
public:
    Solution(vector<int>& nums) :
        nums(nums) {}
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> shuff = nums;
        for (int i = shuff.size() - 1; i >= 0; --i)
            swap(shuff[i], shuff[rand() % (i + 1)]);

        return shuff;
    }
private:
    const vector<int>& nums;
};
