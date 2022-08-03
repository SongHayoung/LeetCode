class Solution {
    unordered_map<int, int> freq;
    bool valid(vector<int>& pick) {
        long long sum = pick[0] + pick[1] + pick[2];
        long long pass = 0;
        for(int i = 0; i < 3; i++)
            pass += sum % pick[i] == 0;
        return pass == 1;
    }
    long long helper(vector<int>& A, vector<int>& pick) {
        if(pick.size() == 3) {
            if(!valid(pick)) return 0;
            long long a = freq[pick[0]];
            long long b = freq[pick[1]];
            long long c = freq[pick[2]];
            if(pick[0] == pick[1]) b--;
            if(pick[0] == pick[2] and pick[1] != pick[2]) c--;
            if(pick[1] == pick[2] and pick[0] != pick[2]) c--;
            if(pick[0] == pick[1] and pick[0] == pick[2]) c -= 2;
            if(a < 0 or b < 0 or c < 0) return 0;
            return a * b * c;
        } else {
            long long res = 0;
            for(int i = 0; i < A.size(); i++) {
                pick.push_back(A[i]);
                res += helper(A,pick);
                pick.pop_back();
            }
            return res;
        }
    }
public:
    long long singleDivisorTriplet(vector<int>& nums) {
        vector<int> A;
        for(auto n : nums) {
            if(freq[n]++ == 0) A.push_back(n);
        }
        return helper(A,vector<int>() = {});
    }
};