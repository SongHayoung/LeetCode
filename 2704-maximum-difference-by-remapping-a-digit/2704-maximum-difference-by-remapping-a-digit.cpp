class Solution {
    int modify(int n, int a, int b) {
        string s = to_string(n);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] - '0' == a) {
                s[i] = '0' + b;
            }
        }
        return stoi(s);
    }
public:
    int minMaxDifference(int num) {
        vector<int> A;
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j <= 9; j++) {
                A.push_back(modify(num,i,j));
            }
        }
        sort(begin(A),end(A));
        return A.back() - A.front();
    }
};