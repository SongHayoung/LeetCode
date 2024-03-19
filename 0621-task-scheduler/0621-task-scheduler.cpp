class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(!n) return tasks.size();
        unordered_map<char, int> m;
        unordered_map<int, int> st;
        int maxCnt = 0, res;
        for(auto& c : tasks){
            maxCnt = max(maxCnt, ++m[c]);
            st[m[c]]++;
        }
        return max((int)tasks.size(), (maxCnt - 1) * (n + 1) + st[maxCnt]);
    }
};