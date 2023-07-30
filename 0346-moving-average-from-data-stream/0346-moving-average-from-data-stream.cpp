class MovingAverage {
    deque<int> dq;
    int sum, sz;
public:
    MovingAverage(int size):sum(0), sz(size), dq({}) {
        
    }
    
    double next(int val) {
        dq.push_back(val);
        sum += val;
        if(dq.size() > sz) {
            sum -= dq.front();
            dq.pop_front();
        }
        return 1. * sum / dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */