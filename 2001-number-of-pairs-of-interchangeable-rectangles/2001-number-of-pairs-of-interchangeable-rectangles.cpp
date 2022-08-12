class Solution {
    string hash(int a, int b) {
        return to_string(a) + "#" + to_string(b);
    }
public:
    long long interchangeableRectangles(vector<vector<int>>& A) {
        long long res = 0;
        unordered_map<string, long long> freq;
        for(auto& a : A) {
            int h = a[0], w = a[1], g = __gcd(h,w);
            h /= g, w /= g;
            res += freq[hash(h,w)]++;
        }
        return res;
    }
};