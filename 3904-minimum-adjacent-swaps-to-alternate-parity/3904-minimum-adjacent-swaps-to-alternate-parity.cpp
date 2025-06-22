
class Solution {
    int helper(vector<int>& A, int P) {
        deque<int> dq[2];
        for(int i = 0; i < A.size(); i++) dq[A[i]&1].push_back(i);
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            int p = i & 1 ? !P : P, np = !p;
            if(dq[p].size() == 0) return INT_MAX;
            if(dq[np].size() == 0) dq[p].pop_front();
            else {
                if(dq[p][0] < dq[np][0]) dq[p].pop_front();
                else {
                    res += dq[p][0] - i;
                    dq[p].pop_front();
                }
            }
        }
        return res;
    }
public:
    int minSwaps(vector<int>& nums) {
        int res = min(helper(nums,0), helper(nums,1));
        return res == INT_MAX ? -1 : res;
    }
};