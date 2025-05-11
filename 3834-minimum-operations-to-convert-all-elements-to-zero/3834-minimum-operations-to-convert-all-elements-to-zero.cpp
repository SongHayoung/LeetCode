class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        vector<int> st{0};
        for(auto& n : nums) {
            while(st.back() > n) st.pop_back();
            if(st.back() < n) {
                res++;
                st.push_back(n);
            }
        }
        return res;
    }
};
