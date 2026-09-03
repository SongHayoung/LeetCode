class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int last = -1, res = 0;
        unordered_map<int,int> freq;
        for(auto& n : nums) {
            if(last != n) {
                freq[n]++;
                if(freq[n] == 1) res++;
                else if(freq[n] == 2) res--;
            }
            last = n;
        }
        return res;
    }
};