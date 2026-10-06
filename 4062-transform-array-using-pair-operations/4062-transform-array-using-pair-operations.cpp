class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum = 0;
        for(int i = 0; i < source.size(); i++) {
            sum = sum + source[i] - target[i];
        }
        return !sum;
    }
};