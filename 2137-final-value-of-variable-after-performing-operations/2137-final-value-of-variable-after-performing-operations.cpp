class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(auto& o : operations) {
            if(o[1] == '-') res--;
            else res++;
        }
        return res;
    }
};