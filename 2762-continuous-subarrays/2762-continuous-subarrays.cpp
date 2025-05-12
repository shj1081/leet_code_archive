class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int n = nums.size();
        long long cnt = 0;
        map<int, int> freq;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            freq[nums[r]]++;  // 오른쪽 확장

            // 최댓값 - 최솟값 > 2 라면 왼쪽 줄이기
            while (prev(freq.end())->first - freq.begin()->first > 2) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);  // 개수 0이면 완전히 삭제
                }
                l++;
            }

            cnt += r - l + 1;  // 현재 구간에서 가장 오늘쪽을 포함하는 가능한 연속 sub vec 수 누적
        }

        return cnt;
    }
};
