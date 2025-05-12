class Solution {
public:

    // | r | hasX          | l | 조건 만족?    | 추가된 개수 (r-l+1) | 총합 |
    // | - | ------------- | - | --------- | -------------- | -- |
    // | 0 | {5:1}         | 0 | ✅         | 1              | 1  |
    // | 1 | {4:1,5:1}     | 0 | ✅         | 2              | 3  |
    // | 2 | {2:1,4:1,5:1} | 0 | ❌ (5-2>2) | → l=1, erase 5 |    |
    // |   | {2:1,4:1}     | 1 | ✅         | 2              | 5  |
    // | 3 | {2:1,4:2}     | 1 | ✅         | 3              | 8  |

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
