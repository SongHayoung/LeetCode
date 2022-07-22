class Solution {
public:
    vector<int> memLeak(int A, int B) {
        int time = 1;
        while(A >= time or B >= time) {
            int& ma = A >= B ? A : B;
            ma -= time++;
        }
        return {time, A, B};
    }
};