class Solution {
public:
    int minSwaps(vector<vector<int>>& A) {
        vector<int> counter;
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = m - 1; j >= 0; j--) {
                if(A[i][j] == 0) cnt++;
                else break;
            }
            counter.push_back(cnt);
        }
        
        int req = m - 1, res = 0;
        for(int i = 0; req; i++,req--) {
            int find = -1;
            for(int j = i; j < n; j++) {
                if(counter[j] >= req) {
                    find = j;
                    break;
                }
            }
            if(find == -1) return -1;
            res += find - i;
            while(find != i) {
                swap(counter[find - 1], counter[find]);
                find--;
            }
        }
        return res;
    }
};