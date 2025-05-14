class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int offset = 0;  // freq[offset]이 현재 'a' 역할

        for (int step = 0; step < t; ++step) {
            // 1) z가 있던 자리에서 개수 꺼내기
            int zPos   = (offset + 25) % 26;  
            int zFreq = freq[zPos];

            // 2) 모든 문자를 다음 글자로 회전
            offset = (offset + 25) % 26;      // ’a’→’b’, …, ’z’→’a’

            // 3) z → “ab” 중 ‘b’만 직접 누적
            int bPos = (offset + 1) % 26;      
            freq[bPos] = (freq[bPos] + zFreq) % MOD;
        }


        int total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + freq[i]) % MOD;
        }

        return static_cast<int>(total);
    }
};
