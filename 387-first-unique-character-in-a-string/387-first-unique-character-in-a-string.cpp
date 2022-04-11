class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        int arr[26]{0,};
        for(int i = 0; i < s.length(); i++) {
            if(++arr[s[i]-'a'] == 1) q.push(i);
        }
        while(!q.empty()) {
            int index = q.front(); q.pop();
            if(arr[s[index]-'a'] == 1) return index;
        }
        return -1;
    }
};