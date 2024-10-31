class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // count of flowers that can be planted (without viloating rules)
        int count = 0;

        // plant the flowers
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                int prev = (i == 0) ? 0 : flowerbed[i - 1]; // consider left end
                int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1]; //consider right end
                if (prev == 0 && next == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }

        // return the result
        return count >= n;
    }
};