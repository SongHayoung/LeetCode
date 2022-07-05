class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto& t : tasks)
            mp[t]++;
        int res = 0;
        for(auto& [k, v] : mp) {
            if(v == 1) return -1;
            
            int a = v / 3, b = v % 3;
            if(b == 0) res += a;
            else res += a + 1;
        }
        return res;
    }
};
