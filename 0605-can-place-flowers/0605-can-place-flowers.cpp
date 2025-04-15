class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int left = n;
        int size = flowerbed.size();

        for (int i = 0; i < size && left > 0; ++i) {
            if (flowerbed[i] == 1) continue;

            bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
            bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);

            if (emptyLeft && emptyRight) {
                flowerbed[i] = 1; // 현재 위치에 꽃을 심는다
                left--;
            }
        }

        return left == 0;
    }
};
