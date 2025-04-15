class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        for (auto it = candies.begin() ; it != candies.end(); it++) {
            if (*it + extraCandies >= max) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};