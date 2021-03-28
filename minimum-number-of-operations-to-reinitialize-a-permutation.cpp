class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> cmp(n), arr(n), perm(n);
        for(int i = 0; i < n; i++) {
            cmp[i] = arr[i] = perm[i] = i;
        }
        
        int res = 0;
        do {
            for(int i = 0; i < n; i++) {
                arr[i] = perm[i % 2 ? n / 2 + (i - 1) / 2 : i / 2];
            }
            perm = arr;
            res++;
        }while(arr != cmp);

        return res;
    }
};
