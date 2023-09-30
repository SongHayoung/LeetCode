class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        long long bit = INT_MAX;
        for(auto& n : nums) bit &= n;
        long long now = INT_MAX;
        if(bit) return 1;
        int res = 0;
        for(auto& n : nums) {
            if(now == bit) {
                cout<<n<<endl;
                now = INT_MAX;
                res += 1;
            }
            now &= n;
        }
        if(now == bit) res += 1;
        return res;
    }
};