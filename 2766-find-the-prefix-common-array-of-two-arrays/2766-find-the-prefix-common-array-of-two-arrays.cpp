class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> freq;
        vector<int> res;
        for(int i = 0, cnt = 0; i < A.size(); i++) {
            if(++freq[A[i]] == 2) cnt++;
            if(++freq[B[i]] == 2) cnt++;
            res.push_back(cnt);
        }
        return res;
    }
};