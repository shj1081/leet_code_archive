class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;

        // *max_element(vector.begin(), vector.end()) returns the max element in the vector
        int origin_max = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++) {
            result.push_back(candies[i] + extraCandies >= origin_max);
        }

        return result;
        
    }
};