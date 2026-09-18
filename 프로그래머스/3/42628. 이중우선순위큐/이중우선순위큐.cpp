#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    
    multiset<int> ms;
   
    for (auto oper : operations)
    {
        if (oper[0] == 'I')
        {
            ms.insert(stoi(oper.substr(2)));
        }
        else if (oper[0] == 'D')
        {
            if (ms.empty()) continue;
            if (oper[2] == '-') ms.erase(*min_element(ms.begin(), ms.end()));
            else ms.erase(*max_element(ms.begin(), ms.end()));
        }
    }

    if (ms.empty()) ms.insert(0);
    answer.emplace_back(*max_element(ms.begin(), ms.end()));
    answer.emplace_back(*min_element(ms.begin(), ms.end()));
    
    return answer;
}