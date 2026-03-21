#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    vector<pair<string, int>> fee_vector;
    unordered_map<string, int> total_times;
    unordered_map<string, int> map;

    for (int i = 0; i < records.size(); i++)
    {
        int time = (records[i][0] * 10 + records[i][1]) * 60 + (records[i][3] * 10 + records[i][4]);
        string id = records[i].substr(6, 4);
        if (records[i][11] == 'I')
        {
            map[id] = time;
        }
        else
        {
            total_times[id] += time - map[id];
            map.erase(id);
        }
    }

    for (auto& items : map)
    {
        total_times[items.first] += ('2' * 10 + '3') * 60 + ('5' * 10 + '9') - map[items.first];
    }
    
    for (auto& items : total_times)
    {
        int fee = 0;
        fee += fees[1];

        if (items.second >= fees[0])
        {
            fee += ceil(float(items.second  - fees[0]) / fees[2]) * fees[3];
        }
        fee_vector.push_back({items.first, fee});
    }
    sort(fee_vector.begin(), fee_vector.end());
    for (auto& items : fee_vector)
        answer.push_back(items.second);
    return answer;
}