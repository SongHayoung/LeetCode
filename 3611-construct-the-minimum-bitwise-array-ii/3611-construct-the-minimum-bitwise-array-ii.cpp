#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto &p : nums){
            if(p < 2){
                ans.push_back(-1);
                continue;
            }
            bool found = false;
            int min_a = INT32_MAX;
            for(int i=0;i<32;i++){
                if(p & (1 << i)){
                    int a_candidate = p & (~(1 << i));
                    if(a_candidate < 0){
                        continue;
                    }
                    // To prevent overflow when a_candidate +1 exceeds integer limits
                    if(a_candidate +1 < 0){
                        continue;
                    }
                    if( (a_candidate | (a_candidate +1)) == p ){
                        if(a_candidate < min_a){
                            min_a = a_candidate;
                            found = true;
                        }
                    }
                }
            }
            if(found){
                ans.push_back(min_a);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};