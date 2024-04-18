class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        vector<vector<int>> res;
        sort(begin(A), end(A));
        for(int i = 0; i < A.size(); i++) {
            if(i and A[i] == A[i-1]) continue;
            for(int j = i + 1; j < A.size(); j++) {
                if(j != i + 1 and A[j-1] == A[j]) continue;
                int l = j + 1, r = A.size() - 1;
                while(l < r) {
                    long sum = 1l * A[i] + A[j] + A[l] + A[r];
                    if(sum < target) l++;
                    else if(sum > target) r--;
                    else {
                        res.push_back({A[i], A[j], A[l], A[r]});
                        int le = A[l], ri = A[r];
                        while(l < r and A[l] == le) l++;
                        while(l < r and A[r] == ri) r--;
                    }
                }
            }
        }
        return res;
    }
};