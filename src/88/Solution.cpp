// My version
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0) {
			for (int i = 0; i != n; ++i)
				nums1[i] = nums2[i];
			return;
		}

		if (n == 0)
			return;

		vector<int> temp(m + n);
		int left = 0;
		int right = 0;
		for (int i = 0; i != m + n; ++i) {
			temp[i] = (nums1[left] <= nums2[right]) ? nums1[left++] : nums2[right++];
			if (left == m) {
				for (int j = i + 1; j != m + n; ++j)
					temp[j] = nums2[right++];

				break;
			}
			else if (right == n) {
				for (int j = i + 1; j != m + n; ++j)
					temp[j] = nums1[left++];

				break;
			}
		}

		nums1 = temp;
    }
};

// Community version
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (j >= 0) {
			if (i >= 0 && nums1[i] > nums2[j])
				nums1[k--] = nums1[i--];
			else
				nums1[k--] = nums2[j--];
		}
	}
};
