class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        // 최대 최소를 빠르게 찾기 위해 자동으로 정렬이 가능한 multiset 사용
        multiset<int> window;
        int left = 0;
        long long res = 0;

        // 윈도우 사용 -> 투포인터를 통해 시간 복잡도 줄이기
        for (int right = 0; right < nums.size(); right++) {
            window.insert(nums[right]);

            // 조건 위반 시 left를 이동하여 
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                left++;
            }

            // 현재 윈도우에서 조건을 만족하는 right를 포함하는 subarray 조합 수 더해주기
            res += right - left + 1;
        }

        return res;
    }
};
