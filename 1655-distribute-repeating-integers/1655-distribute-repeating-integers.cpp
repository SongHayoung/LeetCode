class Solution {
    bool on(int b, int x) {
    return (b>>x) & 1;
}
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n = quantity.size();
    int mask = 1<<n;
    vector<bool> dp(mask);
    dp[0] = true;

    unordered_map<int,int> freq;
    for(auto& n : nums) freq[n]++;
    vector<int> S;
    for(auto& [k,v] : freq) S.push_back(v);
    sort(rbegin(S), rend(S));
    while(S.size() > n) S.pop_back();



    for(auto& cnt : S) {
        vector<int> available;
        for(int bit = 1; bit < mask; bit++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if(on(bit,i)) sum += quantity[i];
            }
            if(sum <= cnt) available.push_back(bit);
        }
        
        for(int i = mask - 1; i >= 0; i--) {
            if(!dp[i]) continue;
            for(auto& avail : available) dp[i | avail] = true;
        }
    }
    return dp[mask-1];
    }
};