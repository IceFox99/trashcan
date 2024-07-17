// My version
class MedianFinder {
public:
    MedianFinder() : nums() {
        nums.reserve(50000);
    }
    
    void addNum(int num) {
        if (nums.empty()) {
            nums.push_back(num);
            return;
        }
        if (num <= nums.front()) {
            nums.insert(nums.begin(), num);
            return;
        } 
        if (num >= nums.back()) {
            nums.push_back(num);
            return;
        }

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (num < nums[(left + right) / 2]) 
                right = min(right - 1, (left + right) / 2);
            else if (num > nums[(left + right) / 2])
                left = max(left + 1, (left + right) / 2);
            else {
                right = (left + right) / 2;
                break;
            }
        }
        nums.insert(nums.begin() + right, num);
    }
    
    double findMedian() {
        int size = nums.size();
        if (size % 2) return nums[size / 2];
        else return ((double)nums[size / 2 - 1] + nums[size / 2]) / 2;
    }

    vector<int> nums;
};

// Community version
class MedianFinder
{
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    /**
     * @brief Rebalances the maxHeap and minHeap to maintain the size property.
     * 
     * @details
     * The invariant maintained is that the size of maxHeap is either equal to the size of minHeap or
     * greater by one. This ensures efficient median finding, where if both heaps are of equal size,
     * the median is the average of the tops of both heaps. If maxHeap has one more element, the median
     * is the top of maxHeap.
     */
    void rebalanceHeaps()
    {
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

public:
    /**
     * @brief Constructor for the MedianFinder class.
     */
    MedianFinder() = default;

    /**
     * @brief Adds a number into the data structure.
     * 
     * @details
     * If the new number is smaller than the maximum of the lower half, it gets added to the max heap,
     * otherwise, it is added to the min heap. After adding, it calls rebalanceHeaps to
     * ensure the size difference between the two heaps is no more than one.
     * 
     * @param num The number to be added.
     */
    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        rebalanceHeaps();
    }

    /**
     * @brief Finds the median of all numbers added so far.
     * 
     * @details
     * If one heap is larger, the median is the top of that heap. If both heaps are the same size,
     * the median is the average of the tops of both heaps.
     * 
     * @return The median of the numbers.
     */
    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            return minHeap.top();
        }
        else
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};
