class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int t = nums.size() / 3;
        int c1 = 0, c2 = 0, n1 = INT_MAX, n2 = INT_MAX;
        for(auto n : nums) {
            if(n1 == n) c1++;
            else if(n2 == n) c2++;
            else if(!c1) n1 = n, c1++;
            else if(!c2) n2 = n, c2++;
            else --c1,--c2;
        }
        
        c1 = c2 = 0;
        for(auto n : nums) {
            if(n1 == n) c1++;
            else if(n2 == n) c2++;
        }
        
        if(c1 > t) res.push_back(n1);
        if(c2 > t) res.push_back(n2);
        
        
        return res;
    }
};