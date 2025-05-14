static const int MOD = 1e9+7;
using ll = long long;
using Mat = vector<vector<ll>>;

// 26×26 행렬 곱
Mat mul(const Mat &A, const Mat &B) {
    Mat C(26, vector<ll>(26, 0));
    for (int i = 0; i < 26; i++) {
        for (int k = 0; k < 26; k++) {
            if (!A[i][k]) continue;
            ll v = A[i][k];
            for (int j = 0; j < 26; j++) {
                C[i][j] = (C[i][j] + v * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// 이진 지수승으로 A^e 계산
Mat matPow(Mat A, ll e) {
    Mat R(26, vector<ll>(26, 0));
    for (int i = 0; i < 26; i++) R[i][i] = 1;
    while (e > 0) {
        if (e & 1) R = mul(R, A);
        A = mul(A, A);
        e >>= 1;
    }
    return R;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // 1) 초기 빈도 벡터
        vector<ll> freq(26, 0);
        for (char c : s) 
            freq[c - 'a']++;

        // 2) 전이 행렬 A 생성
        //    nums[i]=1 for i=0..24, nums[25]=2
        Mat A(26, vector<ll>(26, 0));
        // a..y는 +1씩
        for (int i = 0; i < 25; i++) {
            A[(i + 1) % 26][i] = 1;
        }
        // z는 +1, +2
        A[0][25] = 1;
        A[1][25] = 1;

        // 3) A^t 계산
        Mat At = matPow(A, t);

        // 4) A^t * freq 계산 → 최종 각 문자별 개수
        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = (ans + At[i][j] * freq[j]) % MOD;
            }
        }

        return (int)ans;
    }
};
