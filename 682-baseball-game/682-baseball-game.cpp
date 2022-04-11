class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        for(auto& op : ops) {
            if(op ==  "C") st.pop_back();
            else if(op == "D") st.push_back(st.back() * 2);
            else if(op == "+") st.push_back(st.back() + st[st.size()-2]);
            else st.push_back(stoi(op));
        }
        return accumulate(begin(st),end(st),0);
    }
};