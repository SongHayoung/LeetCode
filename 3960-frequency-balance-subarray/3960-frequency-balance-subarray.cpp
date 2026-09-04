class Solution {
public:
    int getLength(vector<int>& nums) {
        int res = 0, n = nums.size();
        auto update = [&](int x, unordered_map<int,int>& freq, unordered_map<int,int>& rfreq) {
            if(freq[x]) {
                if(--rfreq[freq[x]] == 0) rfreq.erase(freq[x]);
            }
            ++freq[x];
            rfreq[freq[x]]++;
        };
        for(int i = 0; i < n; i++) {
            unordered_map<int,int> freq;
            unordered_map<int,int> rfreq;
            for(int j = i; j < n; j++) {
                update(nums[j],freq,rfreq);
                if(freq.size() == 1) {
                    res = max(res, j - i + 1);
                } else if(rfreq.size() == 2) {
                    int a = 0, b = 0;
                    for(auto& [k,v] : rfreq) {
                        if(a) b = k;
                        else a = k;
                    }
                    if(a < b) swap(a,b);
                    if(a == b * 2) res = max(res, j - i + 1);
                }
                
            }
        }
        return res;
    }
};