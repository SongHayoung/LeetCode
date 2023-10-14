class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> res;
        vector<int> st;
        int cons = 0;
        for(auto w : words) {
            if(w == "prev") {
                cons += 1;
                if(st.size() < cons) {
                    res.push_back(-1);
                } else res.push_back(st[st.size() - cons]);
            } else {
                cons = 0;
                st.push_back(stoi(w));
            }
        }
        return res;
    }
};