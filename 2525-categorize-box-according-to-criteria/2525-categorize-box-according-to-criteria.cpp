class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false;
        if(length >= 1e4 or width >= 1e4 or height >= 1e4 or mass >= 1e4) bulky = true;
        if(1ll * length * width * height >= 1e9) bulky = true;
        bool heavy = mass >= 100;
        if(bulky and heavy) return "Both";
        if(!bulky and !heavy) return "Neither";
        return bulky ? "Bulky" : "Heavy";
    }
};