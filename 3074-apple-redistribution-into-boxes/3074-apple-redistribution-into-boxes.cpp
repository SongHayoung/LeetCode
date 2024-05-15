class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(begin(apple),end(apple),0), res = 0;
        sort(begin(capacity), end(capacity));
        while(sum > 0 and capacity.size()) {
            sum -= capacity.back(); capacity.pop_back();
            res++;
        }
        return res;
    }
};