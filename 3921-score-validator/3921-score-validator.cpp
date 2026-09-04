class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for(int i = 0; i < events.size() and counter < 10; i++) {
            if(events[i] == "W") counter++;
            else if(events[i].length() == 2) score++;
            else score += stoi(events[i]);
        }
        return {score, counter};
    }
};