class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10,0);
        vector<int> res;

        for (int num: digits) {
            cnt[num]++;
        } 

        if (digits.size() == cnt[0]) {
            return res;
        }

        for (int i = 1; i < 10 ; i++) {
            for (int j = 0 ; j < 10; j++) {
                for (int k = 0 ; k < 10; k += 2) {
                   // 개수 소모하면서 유효한지 체크
                    if (cnt[i] > 0 && cnt[j] > 0 && cnt[k] > 0) {
                        cnt[i]--; cnt[j]--; cnt[k]--;
                        if (cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0) {
                            res.push_back(i * 100 + j * 10 + k);
                        }
                        cnt[i]++; cnt[j]++; cnt[k]++;
                    }
                }
            }
        }

        return res;
    }
};