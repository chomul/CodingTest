#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> cnt(N + 1, 0);
    vector<pair<int, float>> arr;
    int total_cnt = stages.size();
    
    for(int i : stages)
        cnt[i]++;

    for(int i = 1; i <= N; i++)
    {
        if(total_cnt == 0) arr.push_back({i, 0});
        else
        {
            arr.push_back({i, float(cnt[i]) / total_cnt});
            total_cnt -= cnt[i];
        }
    }
    
    sort(arr.begin(), arr.end(), 
        [](const pair<int, float>& a, const pair<int, float>& b) 
         { 
            if(a.second == b.second)
                return a.first < b.first;
             else
                 return a.second > b.second;        
        } );
    
    for(auto c : arr)
        answer.push_back(c.first);
    
    return answer;
}