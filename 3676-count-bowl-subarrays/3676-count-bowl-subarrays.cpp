
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> gr(n, -1), le(n, -1), st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() and nums[st.back()] < nums[i]) {
                gr[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st = {};
        for (int i = 0; i < n; ++i) {
            while (!st.empty() and nums[st.back()] < nums[i]) st.pop_back();
            if (!st.empty()) le[i] = st.back();
            st.push_back(i);
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            if (gr[i] != -1 and gr[i] - i >= 2) ++res;
            if (le[i] != -1 and i - le[i] >= 2) ++res;
        }
        return res;
    }
};