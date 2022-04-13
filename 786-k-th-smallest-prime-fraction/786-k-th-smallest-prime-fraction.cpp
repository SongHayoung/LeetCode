class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0.0, r = 1.0;
        int n = arr.size();
        while(l < r) {
            double m = (l + r) / 2, frac = 0.0;
            int a, b, c = 0, j = 1;
            for(int i = 0; i < n - 1; i++) {
                while(j < n and arr[i] > m * arr[j]) j++;
                
                c += n - j;
                if(j == n) break;
                if(frac < 1.0 * arr[i] / arr[j]) {
                    frac = 1.0 * arr[i] / arr[j];
                    a = i, b = j;
                }
            }
            if(c == k) return {arr[a],arr[b]};
            else if(c > k) r = m;
            else l = m;
            
        }
        return {-1,-1};
    }
};