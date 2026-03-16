#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	vector<vector<pair<int, string>>> v;
    int p, m;
	cin >> p >> m;

    while(p--)
    {
        int a;
        string b;
        cin >> a >> b;
       
        if(v.empty())
        {
			v.emplace_back(vector<pair<int, string>>{ {a, b} });
            continue;
        }

        bool chk = false;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i][0].first - 10 <= a && a <= v[i][0].first + 10 && v[i].size() < m)
            {
                v[i].emplace_back(a, b);
                chk = true;
                break;
            }
        }
        if (!chk) v.emplace_back(vector<pair<int, string>>{ {a, b} });
	}

	for(int i = 0; i < v.size(); ++i)
    {
        if (v[i].size() == m)
        {
            cout << "Started!\n";
			sort(v[i].begin(), v[i].end(), [](const pair<int, string>& a, const pair<int, string>& b) { return a.second < b.second; });
            for(int j = 0; j < v[i].size(); ++j)
            {
                cout << v[i][j].first << ' ' << v[i][j].second << '\n';
			}
        }
        else
        {
            cout << "Waiting!\n";
            sort(v[i].begin(), v[i].end(), [](const pair<int, string>& a, const pair<int, string>& b) { return a.second < b.second; });
            for (int j = 0; j < v[i].size(); ++j)
            {
                cout << v[i][j].first << ' ' << v[i][j].second << '\n';
            }
        }
	}


    return 0;
}