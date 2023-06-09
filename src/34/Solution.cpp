// My version
class Solution {
public:
    int findFirst(vector<int>& nums, int target, int start, int end) {
        if (start >= end)
            return end;

        int mid = (start + end) / 2;
        if (nums[mid] < target)
            return findFirst(nums, target, mid + 1, end);
        return findFirst(nums, target, start, mid);
    }

    int findLast(vector<int>& nums, int target, int start, int end) {
        if (end <= start)
            return start;

        int mid = (start + end) / 2;
        if (nums[mid] > target)
            return findLast(nums, target, start, mid - 1);
        else if (mid == start)
            return (nums[end] == target) ? end : mid;
        return findLast(nums, target, mid, end);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else {
                result[0] = findFirst(nums, target, start, mid);
                result[1] = findLast(nums, target, mid, end);
                break;
            }
        }

        return result;
    }
};

// Community version
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums, target);
        int right = lower_bound(nums, target + 1) - 1;
        if (left <= right && nums[left] == target)
            return { left, right };
        else
            return { -1, -1 };
    }
};
