#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    
    int w = 0, time = 0, index = 0;

    // 무게, 들어온 시간
    queue<pair<int, int>> bridge;

    while (true)
    {
        time++;

        if (index >= truck_weights.size()) break;

        if (!bridge.empty() && time - bridge.front().second == bridge_length)
        {
            w -= bridge.front().first;
            bridge.pop();
        }

        if (w + truck_weights[index] <= weight)
        {
            w += truck_weights[index];
            bridge.push({ truck_weights[index], time });
            index++;
        }

    }
    answer = time + bridge_length - 1;
    
    return answer;
}