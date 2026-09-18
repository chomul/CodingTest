#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    // 1. 초기 배열 정렬
    sort(scoville.begin(), scoville.end());

    queue<int> q1; // 원본 스코빌 지수
    queue<int> q2; // 섞어서 새로 만든 스코빌 지수

    for (int s : scoville) {
        q1.push(s);
    }

    // 두 큐 중 가장 작은 값을 꺼내는 람다 함수
    auto getMin = [&]() {
        if (q1.empty()) {
            int val = q2.front(); q2.pop();
            return val;
        }
        if (q2.empty()) {
            int val = q1.front(); q1.pop();
            return val;
        }

        if (q1.front() <= q2.front()) {
            int val = q1.front(); q1.pop();
            return val;
        } else {
            int val = q2.front(); q2.pop();
            return val;
        }
    };

    while (true) {
        // 가장 작은 값이 K 이상인지 확인
        int first = 0;
        if (!q1.empty() && !q2.empty()) {
            first = min(q1.front(), q2.front());
        } else if (!q1.empty()) {
            first = q1.front();
        } else if (!q2.empty()) {
            first = q2.front();
        }

        if (first >= K) return answer;
        if (q1.size() + q2.size() < 2) return -1;

        // 가장 작은 값 2개 추출
        int min1 = getMin();
        int min2 = getMin();

        int mixed = min1 + (min2 * 2);
        q2.push(mixed);
        answer++;
    }

    return answer;
}
