#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int start = 0;
    int end = 0;
    int sum = sequence[start];
    vector<tuple<int, int, int>> v;
    
    while (start < sequence.size() && end < sequence.size())
    {
        if (sum < k)
        {
            end++;
            if (end >= sequence.size()) break;
            sum += sequence[end];
        }
        else if (sum == k)
        {
            v.emplace_back(end - start, start, end);
            sum -= sequence[start];
            start++;
        }
        else if (sum > k)
        {
            sum -= sequence[start];
            start++;
        }
    }

    sort(v.begin(), v.end());
    
    return {get<1>(v[0]), get<2>(v[0])};
}