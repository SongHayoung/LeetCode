class Solution {
    int helper(vector<int>& A, vector<int>& B) {
        int res = 0, i = 0, j = 0, n = A.size(), m = B.size();
        int a = 0, b = 0;
        while(i < n or j < m) {
            if(j < m and i < n) {
                if(B[j] < A[i]) {
                    b++; j++;
                } else {
                    a++; i++;
                }
            } else if(i < n) {a++; i++;}
            else {b++;j++;}
            if(b > a and j != m) {
                b = a = 0;
            }
            if(b)
                res = max(res, a-b);
        }
        
        return res;
    }
public:
    int largestVariance(string s) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.length(); i++)
            mp[s[i]].push_back(i);
        int res = 0;
        for(char i = 'a'; i <= 'z'; i++) {
            for(char j = 'a'; j <= 'z'; j++) {
                if(i == j) continue;
                res = max(res, helper(mp[i], mp[j]));
            }
        }
        return res;
    }
};