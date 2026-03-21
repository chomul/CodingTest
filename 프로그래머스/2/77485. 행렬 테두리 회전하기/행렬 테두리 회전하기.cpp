#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> queryVec(vector<vector<int>>& grid, vector<int>& query)
{
    vector<int> answer;

    for (int i = query[1]; i <= query[3]; i++)
        answer.push_back(grid[query[0]][i]);

    for (int i = query[0] + 1; i <= query[2]; i++)
        answer.push_back(grid[i][query[3]]);

    for (int i = query[3] - 1; i >= query[1]; i--)
        answer.push_back(grid[query[2]][i]);

    for (int i = query[2] - 1; i > query[0]; i--)
        answer.push_back(grid[i][query[1]]);
    
    return answer;
}

void RotationVec(vector<vector<int>>& grid, vector<int>& query, vector<int>& tempVec)
{
    int k = 0;
    for (int i = query[1] + 1; i <= query[3]; i++)
        grid[query[0]][i] = tempVec[k++];

    for (int i = query[0] + 1; i <= query[2]; i++)
        grid[i][query[3]] = tempVec[k++];

    for (int i = query[3] - 1; i >= query[1]; i--)
        grid[query[2]][i] = tempVec[k++];

    for (int i = query[2] - 1; i >= query[0]; i--)
        grid[i][query[1]] = tempVec[k++];

    return;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> grid(rows + 1, vector<int>(columns + 1));
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            grid[i][j] = (i - 1) * columns + j;

    for (auto query : queries)
    {
        vector<int> temp = queryVec(grid, query);
        answer.push_back(*min_element(temp.begin(), temp.end()));
        RotationVec(grid, query, temp);        
    }
    
    return answer;
}
