class Solution {
    int convert(vector<int>& mapping, int n) {
        string num = to_string(n);
        for(int i = 0; i < num.size(); i++) {
            num[i] = mapping[num[i] - '0'] + '0';
        }
        return stoi(num);
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            int cvt = convert(mapping, nums[i]);
            
            pq.push({cvt, i, nums[i]});
        }
        vector<int> res;
        while(!pq.empty()) {
            auto [cvt, idx, num] = pq.top(); pq.pop();
            res.push_back(num);
        }
        return res;
    }
};