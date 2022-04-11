class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool flag = true;
        for(auto& num : nums) {
            if(num < 0)
                flag ^= true;
            if(!num)
                return 0;
        }

        return flag ? 1 : -1;
    }
};
