class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pol = 0, pul=0;
        for(auto n : pushed) {
            pushed[pul++] = n;
            while(pul > 0 and pushed[pul-1] == popped[pol]) {
                pol++;
                pul--;
            }
        }
        return pul == 0;
    }
};