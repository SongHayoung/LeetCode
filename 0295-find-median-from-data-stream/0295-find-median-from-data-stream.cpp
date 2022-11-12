class MedianFinder {
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    bool odd;
public:
    MedianFinder(): odd(false) {}

    void addNum(int num) {
        odd = !odd;
        if(odd) {
            right.push(num);
            left.push(right.top());
            right.pop();
        } else {
            if(left.top() <= num) {
                right.push(num);
            } else {
                right.push(left.top());
                left.push(num);
                left.pop();
            }
        }
    }

    double findMedian() {
        return odd ? left.top() / 1.0 : (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */