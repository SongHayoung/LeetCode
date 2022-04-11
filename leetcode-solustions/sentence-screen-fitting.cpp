class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int sz = sentence.size();
        int totalLen = 0;
        vector<int> len(sz, 0);
        for(int i = 0; i < sentence.size(); i++){
            len[i] = sentence[i].length();
            totalLen += len[i];
            if(len[i] > cols)
                return 0;
        }

        totalLen += sz;

        vector<pair<int, int>> table(sz);
        for(int i = 0; i < sz; i++) {
            int cursor = i, start = totalLen * (cols / totalLen), repeat = cols / totalLen;
            if(start + totalLen - 1 <= cols) {
                start += totalLen - 1;
                repeat++;
            }
            while(start + len[cursor] <= cols) {
                start += (len[cursor] + 1);
                cursor++;

                if(cursor == sz) {
                    cursor = 0;
                }
            }

            table[i].first = repeat;
            table[i].second = cursor;
        }

        int res = 0, jump = 0;
        while(rows--) {
            res += table[jump].first;
            if(jump > table[jump].second)
                res++;
            jump = table[jump].second;
        }

        return res;
    }
};
