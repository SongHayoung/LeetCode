class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 0, bit = 0, mask = 7; i < arr.size(); i++, bit = (bit * 2) & mask) {
            bit ^= (arr[i] & 1);
            if(bit == mask) return true;
        }
        return false;
    }
};