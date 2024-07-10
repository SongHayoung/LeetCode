class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(auto& log : logs) {
            if(log == "../") res = max(0, res - 1);
            else if(log == "./") continue;
            else res++;
        }
        return res;
    }
};