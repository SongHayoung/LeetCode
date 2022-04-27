class Solution {
    vector<int> g;
    int find(int n) {
        return g[n] == n ? n : g[n] = find(g[n]);
    }
    void uni(int a, int b) {
        int pa = find(a), pb = find(b);
        g[pa] = g[pb] = min(pa,pb);
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) { //o(logn*(m + nlogn))
        g = vector<int>(s.length(),0);
        for(int i = 0; i < s.length(); i++) g[i] = i; //o(n)
        for(auto p : pairs) { //o(mlogn)
            uni(p[0], p[1]);
        }
        priority_queue<char, vector<char>, greater<char>> order[s.length()];
        for(int i = 0; i < s.length(); i++) { //o(n * logn * logn) in total
            order[find(i)].push(s[i]); //o(logk) * o(logm)
        }
        for(int i = 0; i < s.length(); i++) { //o(nlogn)
            int n = find(i); //o(1)
            s[i] = order[n].top();
            order[n].pop(); //o(logn)
        }
        return s;
    }
};