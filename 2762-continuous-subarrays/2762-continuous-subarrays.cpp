class Solution {
public:
    static long long continuousSubarrays(vector<int>& nums) {
        long long cnt = 0;
        map<int, int> freq;
        int l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            ++freq[nums[r]];
            while (prev(freq.end())->first - freq.begin()->first > 2) {
                if (--freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                ++l;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
};