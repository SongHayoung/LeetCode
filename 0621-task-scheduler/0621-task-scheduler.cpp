class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        unordered_map<int, int> ma;
        int cnt = 0;
        for(auto& t : tasks) {
            cnt = max(cnt, ++freq[t]);
            ma[freq[t]]++;
        }
        return max((int)tasks.size(), cnt + n * (cnt - 1) + ma[cnt] - 1);
    }
};