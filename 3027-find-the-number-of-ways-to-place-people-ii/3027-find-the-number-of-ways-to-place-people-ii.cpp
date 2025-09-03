class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // sort by x(오름차), y(내림차)
        sort(points.begin(), points.end(), []( const vector<int>& pointA,const vector<int>& pointB) {
            if (pointA[0]!=pointB[0]) {
                return pointA[0] < pointB[0];
            } return pointA[1] > pointB[1];

        });

        int validPairCnt = 0;
        for (int idxA = 0; idxA < points.size(); ++idxA) {
            int yOfPointA = points[idxA][1];
            int highestYofPrevPointB = numeric_limits<int>::min(); // init value

            for (int idxB = idxA+1; idxB < points.size(); ++idxB) {
                int curYofPointB = points[idxB][1];

                // bob should have lower or equal y coord w/ alice
                // in-fence-point `C` that coord is like 
                // - x_A <= x_C <= x_B (cannot happen bcs x is primiary sort key) 
                // - y_A <= y_C <= y_B (should check)
                // should not exist
                if (curYofPointB > highestYofPrevPointB && curYofPointB <= yOfPointA) {
                    ++validPairCnt;
                    highestYofPrevPointB = curYofPointB;
                }
            }
        }

        return validPairCnt;        
    }
};