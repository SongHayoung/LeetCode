class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> check;
        int res = 1;
        for(auto& n : nums) {
            if(1 <= n and n <= 500000) check[n] = true;
            while(check[res]) res++;
        }
        return res;
    }
};