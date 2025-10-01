class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string sign = numerator * denominator < 0 ? "-" : "";
        numerator = abs(numerator);
        denominator = abs(denominator);
        
        long long front = numerator / denominator;
        numerator -= denominator * front;
        if(numerator == 0) return sign + to_string(front);
        
        vector<long long> back;
        unordered_map<long long, long long> mp;
        numerator *= 10;
        while(numerator != 0 and !mp.count(numerator)) {
            mp[numerator] = back.size();
            back.push_back(numerator / denominator);
            numerator -= back.back() * denominator; 
            numerator *= 10;
        }
        long long rep = numerator == 0 ? -1 : mp[numerator];
        string res = "";
        for(long long i = 0; i < back.size(); i++) {
            if(i == rep) res.push_back('(');
            res.push_back(0b110000 | back[i]);
        }
        if(rep != -1) res.push_back(')');
        return sign + to_string(front) + "." + res;
    }
};