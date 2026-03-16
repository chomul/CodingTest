#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>


using namespace std;

int n, m;
int start_n, start_m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dist[1002][1002];

void bfs()
{
	queue<pair<int, int>> q;

	q.push({ start_n, start_m });

    while(!q.empty())
    {
		pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int next_n = current.first + dx[i];
            int next_m = current.second + dy[i];
            if (next_n < 0 || next_n >= n || next_m < 0 || next_m >= m) continue;
            if (dist[next_n][next_m] != -1) continue;
			dist[next_n][next_m] = dist[current.first][current.second] + 1;
			q.push({ next_n, next_m });
        }
    }
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(m));
	fill(dist[0], dist[0] + 1002 * 1002, -1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 0) dist[i][j] = 0;
            if (graph[i][j] == 2)
            {
				start_m = j;
				start_n = i;
                dist[i][j] = 0;
            }
        }
    }

    bfs();

	for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dist[i][j] == -1) dist[i][j] = -1;
			cout << dist[i][j] << " ";
        }
        cout << "\n";
	}
    return 0;
}