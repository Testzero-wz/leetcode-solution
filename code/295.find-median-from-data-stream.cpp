/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
#include <queue>
using namespace std;
// @lc code=start
class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (minHeap.empty() || minHeap.top() <= num)
            minHeap.push(num);
        else
            maxHeap.push(num);

        // rebalance
        if (maxHeap.size() == minHeap.size() || minHeap.size() - 1 == maxHeap.size())
            return;

        if (maxHeap.size() > minHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
