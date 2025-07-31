class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s, memo;
        for(auto& num : arr) {
            unordered_set<int> tmp;
            for(auto& mem : memo) {
                tmp.insert(mem | num);
            }
            memo = tmp;
            memo.insert(num);
            s.insert(begin(memo), end(memo));
        }
        return s.size();
    }
};