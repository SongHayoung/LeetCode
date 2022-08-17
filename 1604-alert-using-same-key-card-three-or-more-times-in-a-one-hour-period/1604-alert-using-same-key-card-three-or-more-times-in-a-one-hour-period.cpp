class Solution {
    int parse(string time) {
        auto p = time.find(':');
        string hour = time.substr(0,p);
        string minitue = time.substr(p + 1);
        return stoi(hour) * 60 + stoi(minitue);
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_set<string> alert;
        unordered_map<string, int> mp;
        vector<pair<int, string>> key;
        for(int i = 0; i < keyName.size(); i++) {
            string name = keyName[i];
            string time = keyTime[i];
            int minute = parse(time);
            key.push_back({minute, name});
        }
        sort(begin(key), end(key));
        
        int l = 0, r = 0, n = key.size();
        while(r < n) {
            while(r < n and key[l].first + 60 >= key[r].first) {
                if(++mp[key[r].second] == 3) alert.insert(key[r].second);
                r++;
            }
            while(r < n and key[l].first + 60 < key[r].first) {
                mp[key[l++].second]--;
            }
        }
        
        vector<string> res(begin(alert), end(alert));
        sort(begin(res), end(res));
        return res;
    }
};