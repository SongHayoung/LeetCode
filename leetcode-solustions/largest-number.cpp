bool compare(const string& a, const string& b) {
    return a + b < b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, std::function<bool(string, string)>> pq(compare);
        stringstream res;

        for(auto num : nums)
            pq.push(to_string(num));

        while(!pq.empty()) {
            res<<pq.top();
            pq.pop();
        }

        return res.get() == '0' ? "0" : res.str();
    }
};
