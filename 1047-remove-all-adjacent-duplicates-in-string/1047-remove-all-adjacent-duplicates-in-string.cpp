class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        queue<char> q;
        for(auto ch : s) q.push(ch);
        while(!q.empty()) {
            while(!st.empty() and st.back() == q.front()) {
                st.pop_back();
                q.pop();
            }
            if(!q.empty()) {
             st.push_back(q.front());
                q.pop();   
            }
        }
        
        stringstream ss;
        for(auto ch : st) ss<<ch;
        return st.empty() ? "" : ss.str();
    }
};