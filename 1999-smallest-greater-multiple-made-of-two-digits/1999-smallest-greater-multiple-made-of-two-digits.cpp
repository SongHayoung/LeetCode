class Solution {
public:
    int findInteger(int k, int digit1, int digit2) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        unordered_set<long long> vis;
        
        auto push = [&](long long n) {
            if(vis.count(n)) return;
            if(n > INT_MAX) return;
            q.push(n);
            vis.insert(n);
        };
        
        push(digit1);
        push(digit2);
        
        while(!q.empty()) {
            auto u = q.top(); q.pop();
            if(u > k and u % k == 0) return u;
            push(u * 10 + digit1);
            push(u * 10 + digit2);
        }
        
        
        return -1;
    }
};