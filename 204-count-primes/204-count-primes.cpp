#define MAXNUM 5000000

class Solution {
    bool is_Prime[(MAXNUM>>1) + 1];
public:
    int countPrimes(int n) {
        if(n <= 3) return n == 3 ? 1 : 0;
        
        int res(1), i;
        memset(is_Prime,true,sizeof(is_Prime));
        is_Prime[0] = false;
        for(i=3; i*i<n;i+=2){
            if(is_Prime[i>>1]){
                for(int j = i*i; j<=n; j += (i<<1)){
                    is_Prime[j>>1] = false;
                }
                res++;
            }
        }
        for(; i < n; i+=2) {
            if(is_Prime[i>>1]) res++;
        }
        return res;
    }
};