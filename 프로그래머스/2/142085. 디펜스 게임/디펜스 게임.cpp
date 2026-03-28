#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    long long sum = 0;
    int cnt = k;
    priority_queue<int> pq;

    for (int i = 0; i < enemy.size(); i++)
    {
        if (sum + enemy[i] > n && cnt == 0)
            break;
        
        sum += enemy[i];
        pq.push(enemy[i]);
        if (sum > n && cnt > 0)
        {
            cnt--;
            sum -= pq.top();
            pq.pop();
        }
    }
    answer = pq.size() + k - cnt;
    return answer;
}
