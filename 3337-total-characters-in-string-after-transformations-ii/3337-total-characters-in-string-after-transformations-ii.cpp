#include <bits/stdc++.h>
using namespace std;

static constexpr int L = 26;
static constexpr int MOD = 1000000007;

// 고정 크기 L×L 행렬 타입
struct Mat {
    int a[L][L];

    // 0으로 초기화
    Mat() { 
        memset(a, 0, sizeof(a));
    }

    // 복사 생성자
    Mat(const Mat &that) {
        for (int i = 0; i < L; ++i)
            for (int j = 0; j < L; ++j)
                a[i][j] = that.a[i][j];
    }

    // 대입 연산자
    Mat& operator=(const Mat &that) {
        if (this != &that) {
            for (int i = 0; i < L; ++i)
                for (int j = 0; j < L; ++j)
                    a[i][j] = that.a[i][j];
        }
        return *this;
    }

    // 행렬 곱셈
    Mat operator*(const Mat &o) const {
        Mat r;
        for (int i = 0; i < L; ++i) {
            for (int k = 0; k < L; ++k) {
                if (a[i][k] == 0) continue;
                long long v = a[i][k];
                for (int j = 0; j < L; ++j) {
                    r.a[i][j] = (r.a[i][j] + v * o.a[k][j]) % MOD;
                }
            }
        }
        return r;
    }
};

// 이진 지수승으로 A^e 계산
Mat matPow(Mat base, long long e) {
    Mat res;
    // 단위 행렬
    for (int i = 0; i < L; ++i) 
        res.a[i][i] = 1;

    while (e > 0) {
        if (e & 1) res = res * base;
        base = base * base;
        e >>= 1;
    }
    return res;
}

class Solution {
public:
    int lengthAfterTransformations(string s, long long t, vector<int>& nums) {
        // 1) 초기 빈도 벡터
        vector<long long> freq(L, 0);
        for (char c : s) 
            freq[c - 'a']++;

        // 2) 전이 행렬 A 구성 (하나의 round 진행 했을 떄 어떻게 변환되는지를 기술하는 matrix)
        Mat A;
        for (int i = 0; i < L; ++i) {
            for (int d = 1; d <= nums[i]; ++d) {
                int j = (i + d) % L;
                A.a[i][j] = 1;
            }
        }

        // 3) A^t 계산
        Mat At = matPow(A, t);

        // 4) A^t * freq 벡터 곱해서 최종 freqT 계산
        vector<long long> freqT(L, 0);
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < L; ++j) {
                freqT[j] = (freqT[j] + At.a[i][j] * freq[i]) % MOD;
            }
        }

        // 5) 최종 문자열 길이 = 모든 freqT 합
        long long ans = 0;
        for (int i = 0; i < L; ++i)
            ans = (ans + freqT[i]) % MOD;

        return (int)ans;
    }
};
