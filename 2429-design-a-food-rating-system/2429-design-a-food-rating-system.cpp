class Compare {
public:
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

class FoodRatings {
    unordered_map<string, string> cmp;
    unordered_map<string, int> rmp;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>> rate;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            cmp[foods[i]] = cuisines[i];
            rmp[foods[i]] = ratings[i];
            rate[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        rmp[food] = newRating;
        rate[cmp[food]].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto& heap = rate[cuisine];
        while(1) {
            auto [r, name] = heap.top();
            if(rmp[name] == r) return name;
            heap.pop();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */