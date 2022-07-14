class Solution {
public:
    int bestRotation(vector<int>& A) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = A.size(), res = 0, score = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] > i) continue;
            q.push(i - A[i]);
        }
        score = q.size();
        for(int i = 0, j = 1; i < n; i++, j++) {
            while(!q.empty() and q.top() < j) q.pop();
            if(A[i] > n - 1) continue;
            q.push(j + n - 1 - A[i]);
            if(score < q.size()) {
                score = q.size();
                res = j;
            }
        }
        
        return res;
    }
};