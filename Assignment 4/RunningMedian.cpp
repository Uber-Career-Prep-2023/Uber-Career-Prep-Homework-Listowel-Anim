#include <iostream>
#include <queue>
#include <functional>

// Time Spent : 32 minutes
// Technique Applied: Maintaining two heaps
class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= -maxHeap.top()) {
            maxHeap.push(-num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(-maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(-minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (-maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return -maxHeap.top();
        }
    }

private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

int main() {
    MedianFinder medianFinder;
    std::vector<int> inputs = {1, 11, 4, 15, 12};

    for (int num : inputs) {
        medianFinder.addNum(num);
        std::cout << medianFinder.findMedian() << std::endl;
    }

    return 0;
}
