class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> freq;
        vector<int> res;
        for(long long i = 1; 2 * i * i * i <= n; i++) {
            for(long long j = i; i * i * i + j * j * j <= n; j++) {
                if(++freq[i * i * i + j * j * j] == 2) res.push_back(i * i * i + j * j * j);
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};