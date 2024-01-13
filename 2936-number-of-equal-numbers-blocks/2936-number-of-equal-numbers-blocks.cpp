/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int countBlocks(BigArray* nums) {
        long long res = 0, n = nums->size(), lst = nums->at(n-1);
        for(long long i = 0, j = 0; i < n; i = j + 1) {
            long long skip = 1, val = nums->at(i);
            if(lst == val) {
                return res + 1;
            }
            while(1) {
                if(nums->at(min(j+skip,n-1)) != val) {
                    if(skip == 1) break;
                    skip = 1;
                } else j += skip, skip *= 2;
            }
            res += 1;
        }

        return res;
    }
};