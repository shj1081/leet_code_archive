class Solution {
public:
    static long long continuousSubarrays(vector<int>& nums) {
        const int n = nums.size();
        long long cnt = 0;
        multiset<int> window;
        int l = 0;

        for (int r = 0; r < n; r++) {
            window.insert(nums[r]);

            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[l]));
                l++;
            }

            cnt += r - l + 1;
        }

        return cnt;
    }
};
