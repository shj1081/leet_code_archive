class Solution {
public:
    static long long continuousSubarrays(vector<int>& nums) {
        const int n=nums.size();
        long long cnt=0;
        map<int, int> hasX;
        for(int l=0, r=0; r<n; r++){
            hasX[nums[r]]++;  // 오른쪽 확장
            while(l<r && prev(hasX.end())->first - hasX.begin()->first > 2){
                int f = --hasX[nums[l]];  // 왼쪽 축소
                if (f == 0) hasX.erase(nums[l]); // 0되면 제거
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
};
