class Solution {
    pair<int, int> parse(string& s) {
        int i = 0, f = 0, e = 0, n = s.length();
        while(i < n and s[i] != '.') {
            f = f * 10 + (s[i++] & 0b1111);
        }
        i++;
        while(i < n) {
            e = e * 10 + (s[i++] & 0b1111);
        }
        //while(e and (int)log10(e) != 2) e = e * 10;
        return {f, e};
    }
public:
    string minimizeError(vector<string>& prices, int target) {
        int sum = 0, count = prices.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& p : prices) {
            auto [f, e] = parse(p);
            sum += f;
            if(e) {
                sum += 1;
                pq.push(e);
            } else {
                count -= 1;
            }
        }
        
        if(sum < target or sum - count > target) return "-1";
        int req = sum - target;
        int res = 0;
        while(req--) {
            res += pq.top(); pq.pop();
        }
        while(!pq.empty()) {
            res += 1000 - pq.top(); pq.pop();
        }
        string f = to_string(res / 1000), e = to_string(res % 1000);
        while(e.length() != 3) e = '0' + e;
        return f + "." + e;
    }
};