class MedianFinder {
private:
    priority_queue<int> low; // Max-heap
    priority_queue<int, vector<int>, greater<int>> high; // Min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();

        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() > high.size())
            return low.top();
        return (low.top() + high.top()) / 2.0;
    }
};