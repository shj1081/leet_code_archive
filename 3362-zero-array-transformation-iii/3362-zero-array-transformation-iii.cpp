/*
───────────────────────────────────────────────────────────────────────────────
 문제 요약
 ─────────
 • nums[i] = k  ➔  인덱스 i는 최소 k장의 “감점 티켓(구간)”이 자신을 포함해야 0으로 감소 가능
 • queries[j] = [l, r]  ➔  구간 [l, r] 내 모든 원소를 “최대 1”씩만 감소시키는 티켓 1장
 • 목표: 가능한 한 많은 티켓을 버리면서도 남은 티켓으로 모든 인덱스 수요(nums)를 충족
   ↳ 불가능하면 -1, 가능하면 (버릴 수 있는 티켓 수) 반환

 알고리즘 개요 (Greedy)
 ──────────────────────
 1. queries를 왼쪽 l 기준 오름차순 정렬
 2. time (= 배열 인덱스) 0 → n-1 을 순차 방문
    ▸ available  : 현재 time 이전에 열렸고 아직 배정되지 않은 구간들의 r를 담는 최대 힙
    ▸ assigned   : 이미 ‘사용 중’인 구간들의 r를 담는 최소 힙
    ▸ 불변식      : 루프 종료 직후 assigned.size() == nums[time] (현재 인덱스 수요 충족)
 3. 단계별 처리
    a) assigned.top() < time 인 구간은 범위 종료 → pop
    b) queries 중 l ≤ time 인 구간을 available 에 push
    c) assigned.size() < nums[time] 이면,
       available에서 r가 가장 큰 구간부터 pop → assigned에 push
       (가장 긴 구간이 미래 인덱스까지 덮을 잠재력이 높기 때문)
    d) 그래도 부족하면 즉시 -1
 4. 끝까지 완료되면 쓴 티켓 수 = count, 버린 티켓 = queries.size() - count

 Greedy Optimality Proof (교환 논법)
 ────────────────────────────────────
 • 어떤 최적 해 OPT가 time 에서 길이 짧은 구간 o(Ro) 를 사용하고,
   Greedy는 더 긴 구간 g(Rg ≥ Ro) 를 선택했다고 하자.
 • OPT에서 o를 제거하고 g를 넣어도
   ↳ time 을 포함 (Ro ≥ time)           ✔
   ↳ Ro 이하 영역은 그대로, Ro~Rg 는 더 많이 덮음 ✔
 • 비용(사용 티켓 수)은 동일 → OPT를 Greedy 선택으로 교체 가능
 • 모든 인덱스에 대해 반복하면 최종적으로 Greedy == OPT

 시간·공간 복잡도
 ────────────────
 • 정렬 O(m log m)  (m = |queries|)
 • 인덱스 순회 O((n+m) log m)   (각 단계 힙 연산 ≤ 3회)
 • 공간 O(m)       (두 힙 + 정렬 배열)

───────────────────────────────────────────────────────────────────────────────
*/


// 결과적으로 l이 현재 루프에서 num의 인덱스보다 작은 것 중에 r값이 가장 큰 query를 우선 사용하게 되니 (greedy)
// 범위가 넓은 query들을 먼저 소모하여 효율적으로 필요한 쿼리만 먼저 사용 가능

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {

        /* 1) 왼쪽 l 기준으로 정렬
              - time(인덱스)을 진행하며 l ≤ time인 구간을 빠르게 꺼내기 위함          */
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        /* 2) available: 아직 배정되지 않은 “사용 가능” 구간들의 r를 저장하는 최대 힙
              assigned : 이미 배정되어 사용 중인 구간들의 r를 저장하는 최소 힙          */
        priority_queue<int>                          available; // max-heap
        priority_queue<int, vector<int>, greater<int>> assigned; // min-heap

        int usedCnt = 0;   // 실제로 배정(사용)한 티켓 수
        int k = 0;         // queries를 순회할 포인터

        /* 3) 배열 왼쪽 → 오른쪽으로 진행하며 수요를 충족                    */
        for (int time = 0; time < (int)nums.size(); ++time) {

            /* 3-A. 범위를 벗어난 사용-중 구간 제거: r < time                  */
            while (!assigned.empty() && assigned.top() < time)
                assigned.pop();

            /* 3-B. l ≤ time인 모든 구간을 available 힙에 push               */
            while (k < (int)queries.size() && queries[k][0] <= time)
                available.push(queries[k++][1]);    // r 값을 push

            /* 3-C. 현재 인덱스의 수요(nums[time])만큼 배정이 없으면
                      available에서 r가 가장 큰 구간부터 배정                   */
            while ((int)assigned.size() < nums[time] &&
                   !available.empty() &&
                   available.top() >= time) {       // time을 실제로 포함하는지 확인
                assigned.push(available.top());
                available.pop();
                ++usedCnt;
            }

            /* 3-D. 여전히 부족하다면 실패(0으로 만들 수 없음)                */
            if ((int)assigned.size() < nums[time])
                return -1;
        }

        /* 4) 전체 수요 충족 → 버릴 수 있는 티켓 = 전체 - 사용한 수 */
        return static_cast<int>(queries.size()) - usedCnt;
    }
};

