class Solution {
    unordered_map<int, int> m;
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        for(int i = 0; i < target.size(); i++) {
            m[target[i]] = i;
        }
        vector<int> st{-987654321};
        for(auto& n : arr) {
            if(!m.count(n)) continue;
            if(st.back() < m[n]) {
                st.push_back(m[n]);
            } else {
                auto it = lower_bound(st.begin(), st.end(), m[n]);
                *it = m[n];
            }
        }

        return target.size() - st.size() + 1;
    }
};