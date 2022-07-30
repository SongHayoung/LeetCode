class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for(auto& t : triplets) {
            int aa = t[0], bb = t[1], cc = t[2];
            if(aa > target[0] or bb > target[1] or cc > target[2]) continue;
            a = max(aa, a);
            b = max(bb, b);
            c = max(cc, c);
        }
        return target[0] == a and target[1] == b and target[2] == c;
    }
};