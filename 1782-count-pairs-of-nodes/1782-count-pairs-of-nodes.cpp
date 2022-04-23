class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> c(n + 1), sc, res;
        vector<unordered_map<int, int>> common(n + 1);
        for(auto& e : edges) {
            c[e[0]]++;
            c[e[1]]++;
            common[min(e[0],e[1])][max(e[0],e[1])]++;
        }
        sc = c;
        sort(begin(sc), end(sc));
        unordered_map<int, int> cache;
        for(auto& q : queries) {
            if(!cache.count(q)) {
                int sum = 0;
                
                for(int i = 1, j = n; i < j;) {
                    if(q < sc[i] + sc[j]) {
                        sum += j - i;
                        j--;
                    } else i++;
                }
                
                for(int i = 1; i <= n; i++) {
                    for(auto [j, com] : common[i]) {
                        if(q < c[i] + c[j] and q >= c[i] + c[j] - com)
                            sum--;
                    }
                }
                
                cache[q] = sum;
            }
            res.push_back(cache[q]);
        }
        
        return res;
    }
};