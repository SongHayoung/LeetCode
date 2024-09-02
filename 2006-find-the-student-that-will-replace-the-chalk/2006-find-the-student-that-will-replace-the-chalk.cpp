class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(auto& x : chalk) sum += x;
        k %= sum;
        long long now = 0;
        for(int i = 0; i < chalk.size(); i++) {
            now += chalk[i];
            if(now > k) return i;
        }
        return 0;
    }
};