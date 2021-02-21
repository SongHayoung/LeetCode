class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length(), 0);
        int lower = boxes[0] == '0' ? 0 : 1, lowerCnt = boxes[0] == '0' ? 0 : 1;
        int upper = 0, upperCnt = 0;
        for(int i = 1; i < boxes.length(); i++) {
            if(boxes[i] == '1') {
                upper += i;
                upperCnt++;
            }
        }
        ans[0] = upper;
        for(int i = 1; i < ans.size(); i++) {
            if(boxes[i] == '1') {
                upperCnt--;
                upper--;
            }
            upper -= upperCnt;
            ans[i] = lower + upper;
            lower += lowerCnt;
            if(boxes[i] == '1') {
                lowerCnt++;
                lower++;
            }
        }

        return ans;
    }
};
