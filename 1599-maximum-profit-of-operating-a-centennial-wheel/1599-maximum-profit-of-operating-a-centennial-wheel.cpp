class Solution {
public:
    int minOperationsMaxProfit(vector<int>& C, int b, int r) {
        if(b * 4 <= r) return -1;
        int wait = 0;
        pair<int,int> best{0,-1};
        pair<int,int> now{0,0};
        reverse(begin(C), end(C));
        while(C.size() or wait) {
            if(C.size()) {
                wait += C.back();
                C.pop_back();
            }
            int mi = min(4, wait);
            now.first += mi * b - r;
            now.second++;
            if(best.first < now.first) best = now;
            wait -= mi;
        }
        return best.second;
    }
};