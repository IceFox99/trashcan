// My version
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        bool isOdd = (m + n) % 2;
        int total_num = (m + n) / 2 + 1;
        auto median = [&](int m_num) -> double {
            int n_num = total_num - m_num;
            if (!m_num) return isOdd ? nums2[n_num - 1] : 
                ((double)nums2[n_num - 1] + nums2[n_num - 2]) / 2;
            if (!n_num) return isOdd ? nums1[m_num - 1] :
                ((double)nums1[m_num - 1] + nums1[m_num - 2]) / 2;
            if (isOdd) return max(nums1[m_num - 1], nums2[n_num - 1]);
            multiset<int> res;
            res.insert(nums1[m_num - 1]); res.insert(nums2[n_num - 1]);
            if (m_num > 1) res.insert(nums1[m_num - 2]);
            if (n_num > 1) res.insert(nums2[n_num - 2]);
            return ((double)*res.rbegin() + *(++res.rbegin())) / 2;
        };
        if (!m) return median(0);
        if (!n) return median(total_num);

        int mnum = m / 2 + 1, nnum = total_num - mnum;
        int left = 0, right = m;
        while (left < right) {
            if (nums1[mnum - 1] == nums2[nnum - 1]) return median(mnum);
            if (nums1[mnum - 1] < nums2[nnum - 1]) {
                if (mnum == m || nums1[mnum] >= nums2[nnum - 1]) return median(mnum);
                left = mnum + 1;
                mnum = min(total_num, (mnum + right + 1) / 2);     
            }
            else {
                if (nnum == n || nums1[mnum - 1] <= nums2[nnum]) return median(mnum);
                right = mnum - 1;
                mnum = (mnum + left) / 2;  
            }
            nnum = total_num - mnum;
        }
        return median(mnum);
    }
};

// Community version
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while(low<=high) {
           	int part1 = (low+high) >>1 ;
           	int part2 = (n1+n2+1)/2 - part1;
           
            int left1 = part1 ==0 ? INT_MIN : nums1[part1-1];
            int left2 = part2 ==0 ? INT_MIN : nums2[part2-1];
            
            int right1 = part1==n1 ? INT_MAX : nums1[part1];
            int right2 = part2==n2 ? INT_MAX : nums2[part2];
            
            if(left1 <= right2 && left2<=right1)
            {
                if((n1+n2) % 2 == 0) return (max(left1,left2)+min(right1,right2))/2.0;
                else return max(left1,left2);
            }
            else if(left1>right2) high = part1-1;
            else low = part1+1;
        }
        return 0.0;
    }
};
