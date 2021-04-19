class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int a = 3; a >= 0; a--) {
            if(arr[a] >= 3) continue;
            for(int b = 3; b >= 0; b--) {
                if(a == b || (arr[a] == 2 && arr[b] >= 4)) continue;
                for(int c = 3; c >= 0; c--) {
                    if(a == c || b == c || arr[c] >= 6) continue;
                    for(int d = 3; d >= 0; d--) {
                        if(a == d || b == d || c == d) continue;
                        return to_string(arr[a]) + to_string(arr[b]) + ":" + to_string(arr[c]) + to_string(arr[d]);
                    }
                }
            }
        }

        return "";
    }
};
