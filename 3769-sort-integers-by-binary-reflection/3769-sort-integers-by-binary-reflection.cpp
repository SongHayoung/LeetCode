class Solution {
    int rev(int x) {
        int res = 0;
        while(x) {
            res = res * 2 + (x & 1);
            x /= 2;
        }
        return res;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> S;
        for(auto& n : nums) S.push_back({rev(n),n});
        sort(begin(S), end(S));
        vector<int> res;
        for(auto& [a,b] : S) res.push_back(b);
        return res;
    }
};