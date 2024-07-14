class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
         std::sort(horizontalCut.rbegin(), horizontalCut.rend());
        std::sort(verticalCut.rbegin(), verticalCut.rend());

        long long totalCost = 0;
        int horizontalPieces = 1;
        int verticalPieces = 1;

        int i = 0, j = 0;
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] > verticalCut[j]) {
                totalCost += horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                totalCost += verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        // Add the remaining cuts
        while (i < horizontalCut.size()) {
            totalCost += horizontalCut[i] * verticalPieces;
            i++;
        }

        while (j < verticalCut.size()) {
            totalCost += verticalCut[j] * horizontalPieces;
            j++;
        }

        return totalCost;
    }
};