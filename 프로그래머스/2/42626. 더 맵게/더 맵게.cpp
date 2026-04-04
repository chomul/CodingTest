#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    if (pq.top() >= K) return answer;
    
    while (pq.size() > 1)
    {
        long long temp = 0;
        temp += pq.top();
        pq.pop();

        temp += 2 * pq.top();
        pq.pop();

        answer++;
        pq.push(temp);
        if (pq.top() < K) continue;
        else return answer;
    }
    
    return -1;
}