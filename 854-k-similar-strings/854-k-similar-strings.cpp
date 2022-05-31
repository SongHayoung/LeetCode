class Solution {
public:
    int kSimilarity(string A, string B) {
        for(int i = 0; i < A.length(); i++) {
            if(A[i] == B[i]) continue;
            vector<int> match;
            int res = INT_MAX;
            for(int j = i + 1; j < A.length(); j++) {
                if(B[i] != A[j]) continue;
                match.push_back(j);
                if(B[j] == A[i]) {
                    swap(A[i], A[j]);
                    return 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1));
                }
            }
            
            for(auto& j : match) {
                swap(A[i], A[j]);
                res = min(res, 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1)));
                swap(A[i], A[j]);
            }
            
            return res;
        }
        return 0;
    }
};