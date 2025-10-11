class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<int> A;
        for(auto& ch : s) {
            if(ch == '(') {
                if(A.size() == 0 or A.back() < 0) A.push_back(1);
                else A.back()++;
            } else {
                if(A.size() == 0 or A.back() > 0) A.push_back(-1);
                else A.back()--;
            }
            if(A.size() >= 2 and A.back() == -k and A[A.size()-2] >= k) {
                A.pop_back();
                A.back() -= k;
                if(A.back() == 0) A.pop_back();
            }
        }
        string res = "";
        for(auto& cnt : A) res += string(abs(cnt), cnt < 0 ? ')' : '(');
        return res;
    }
};