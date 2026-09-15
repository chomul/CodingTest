#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> vec;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            vec.push_back(stoi(answer));
            answer = "";
        }

        else
            answer += s[i];
    }
            vec.push_back(stoi(answer));
            answer = "";
    answer = to_string(*min_element(vec.begin(), vec.end())) + " " + to_string(*max_element(vec.begin(), vec.end()));
    
    return answer;
}