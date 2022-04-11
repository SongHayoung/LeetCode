class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz, -1);
        stack<int> st;
        for(int i = 0; i < sz<<1; i++) {
            while(st.size() && nums[st.top()] < nums[i % sz]) {
                res[st.top()] = nums[i % sz];
                st.pop();
            }
            st.push(i % sz);
        }
        return res;
    }
};