class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        priority_queue<int> pq;
        long long sum = 0;
        for(auto& t : target) {
            sum += t;
            pq.push(t);
        }
        while(pq.top() != 1) {
            long long tp = pq.top(); pq.pop();
            long long stp = pq.top();
            long long remain = sum - tp;
            long long n = ceil(1.0 * (sum - stp) / remain) - 1;
            long long origin = tp - n * remain;
            if(origin == tp) origin = tp * 2 - sum;
            if(origin < 1) return false;
            pq.push(origin);
            sum = sum - tp + origin;
        }
        
        return true;
    }
};