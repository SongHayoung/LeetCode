class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> freq;
        for(auto m : moves) freq[m] += 1;
        return freq['L'] == freq['R'] and freq['U'] == freq['D'];
    }
};