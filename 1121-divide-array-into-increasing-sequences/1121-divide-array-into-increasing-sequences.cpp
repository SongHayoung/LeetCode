class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        if(k == 1) return true;
        unordered_map<int, int> freq;
        for(auto& n : nums) freq[n]++;
        
        int mafreq = -1, f = -1;
        for(auto& [n, c] : freq) {
            if(c > f) {
                mafreq = n;
                f = c;
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        freq[mafreq] = 0;
        pq.push({1, f});
        
        for(auto& [n, c] : freq) {
            if(c == 0) continue;
            if(pq.empty()) break;
            while(c and !pq.empty()) {
                auto [len, count] = pq.top(); pq.pop();
                if(count <= c) {
                    len += 1;
                    c -= count;
                    if(len == k) continue;
                    else pq.push({len, count});
                } else {
                    pq.push({len, count - c});
                    if(len + 1 < k)
                        pq.push({len + 1, c});
                    c = 0;
                }
            }
        }
        
        return pq.empty();
    }
};