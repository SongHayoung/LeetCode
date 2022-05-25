class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        unordered_map<int, int> freq;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                freq[((i % sideLength) * sideLength + (j % sideLength))]++;
            }
        }
        priority_queue<int> pq;
        for(auto& [_, c] : freq)
            pq.push(c);
        int res = 0;
        while(!pq.empty() and maxOnes) {
            res += pq.top(); pq.pop();
            maxOnes--;
        }
        return res;
    }
};