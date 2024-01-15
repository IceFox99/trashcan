// My version
class Solution {
public:
    int trap(vector<int>& height) {
		int hsize = height.size();
		if (hsize < 3)
			return 0;
		
		int last = 0, next = 0; 
		
		// index vector which contains left and right boundary
		vector<int> index; 

		for (int i = 0; i != hsize; ++i) {
			if (i == hsize - 1)
				next = 0;
			else
				next = height[i + 1];

			if (height[i] >= last && height[i] > next) {
				while (index.size() > 1 && 
						height[i] >= height[index.back()] && 
						height[index.back()] < height[*(index.rbegin() + 1)])
					index.pop_back();

				index.push_back(i);
			}
			last = height[i];
		}

		if (index.size() < 2)
			return 0;

		int min, sum = 0;
		for (int i = 0; i != index.size() - 1; ++i) {
			min = (height[index[i]] < height[index[i + 1]]) ? 
				height[index[i]] : height[index[i + 1]];
			for (int j = index[i] + 1; j != index[i + 1]; ++j)
				sum += (min > height[j] ? min - height[j] : 0);
		}

		return sum;
    }
};

// Community version
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }   
};
