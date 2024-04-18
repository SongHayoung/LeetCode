class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for(auto& x : pushed) {
            while(i and j < popped.size() and popped[j] == pushed[i-1]) {
                i--,j++;
            }
            pushed[i++] = x;
        }
         while(i and j < popped.size() and popped[j] == pushed[i-1]) {
            i--,j++;
        }
        return !i;
    }
};