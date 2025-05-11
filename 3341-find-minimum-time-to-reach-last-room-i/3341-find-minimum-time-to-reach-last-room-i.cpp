class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        using T = tuple<int, int, int>; // time, x, y
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});
        minTime[0][0] = 0;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top(); 
            pq.pop();
            if (x == n - 1 && y == m - 1) 
                return t;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                    continue;

                int wait = max(t, moveTime[nx][ny]);
                int nextT = wait + 1;

                if (nextT < minTime[nx][ny]) {
                    minTime[nx][ny] = nextT;
                    pq.push({nextT, nx, ny});
                }
            }
        }

        return -1;
    }
};