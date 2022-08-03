class Solution {
    string eval(vector<int>& A, vector<int>& B) {
        int y1 = A[0], x1 = A[1], y2 = B[0], x2 = B[1];
        if(x1 == x2) return "##" + to_string(x1);
        if(y1 == y2) return to_string(y1) + "##";
        int a = y2 - y1, b = x2 - x1;
        
        int g = __gcd(a,b);
        a /= g, b /= g;
        if(a < 0) {
            a = -a;
            b = -b;
        }
        long double c = y1 - 1.0 * a / b * x1;
        return to_string(a) + "#" + to_string(b) + "#" + to_string(c);
    }
public:
    int minimumLines(vector<vector<int>>& A) {
        if(A.size() == 0) return 0;
        if(A.size() == 1) return 1;
        unordered_map<string, unordered_set<int>> freq;
        for(int i = 0; i < A.size(); i++) {
            for(int j = i + 1; j < A.size(); j++) {
                string line = eval(A[i], A[j]);
                freq[line].insert(i);
                freq[line].insert(j);
            }
        }
        string line = "";
        int cnt = 0;
        for(auto [l, c] : freq) {
            if(c.size() > cnt) {
                cnt = c.size();
                line = l;
            }
        }
        vector<vector<int>> B;
        for(int i = 0; i < A.size(); i++) {
            if(!freq[line].count(i)) B.push_back(A[i]);
        }
        
        return 1 + minimumLines(B);
    }
};