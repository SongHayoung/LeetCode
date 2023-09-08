class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k>26) return "";
        stringstream ss;
        int arr[26]{0};
        int last[26];
        for(int i = 0; i < 26; i++) last[i] = -1;
        priority_queue<pair<int,char>> pq;
        queue<char> q; 
        for(auto ch : s) {
            arr[ch-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i]) pq.push({arr[i], i + 'a'});
        }
        int len = 0;
        while(!pq.empty()) {
            auto [_, ch] = pq.top(); pq.pop();
            ss<<ch;
            last[ch-'a'] = len++;
            if(--arr[ch-'a'] != 0) {
                q.push(ch);
            }
            if(!q.empty() and last[q.front()-'a'] + k <= len) {
                pq.push({arr[q.front()-'a'], q.front()});
                q.pop();
            }
        }
        
        if(q.empty()) {
            return ss.str();
        }
        return "";
        
        
    }
};