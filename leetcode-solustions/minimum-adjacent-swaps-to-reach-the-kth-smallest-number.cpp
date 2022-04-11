class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;
        while(k--) next_permutation(begin(target), end(target));
        int res = 0, pos = 0;
        while(num != target) {
            if(num[pos] != target[pos]) {
                int find = target.find(num[pos], pos);
                while(find != pos) {
                    swap(target[find], target[find - 1]);
                    res++;
                    find--;
                }
            } 
            pos++;
        }
        return res;
    }
};
