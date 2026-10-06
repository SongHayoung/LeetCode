class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> ord;
        for(int i = 0; i < nums.size(); i++) {
            ord[nums[i]].push_back(i);
        }
        int res = 0;
        auto ok = [&](vector<int>& A) {
            if(A.size() < 3) return false;
            int d = A[1] - A[0];
            for(int i = 2; i < A.size(); i++) {
                if(A[i] - A[i-1] != d) return false;
            }
            return true;
        };
        for(auto& [_,at] : ord) {
            res += ok(at);
        }
        return res;
    }
};