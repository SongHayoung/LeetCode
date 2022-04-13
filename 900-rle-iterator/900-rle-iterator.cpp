class RLEIterator {
    queue<pair<int, int>> order;
public:
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size(); i+=2) {
            if(encoding[i])
                order.push({encoding[i], encoding[i+1]});
        }
    }

    int next(int n) {
        int res = -1;
        while(n and !order.empty()) {
            int remove = min(n, order.front().first);
            n -= remove;
            if(!n) res = order.front().second;
            order.front().first -= remove;
            if(!order.front().first) order.pop();
        }
        return res;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
