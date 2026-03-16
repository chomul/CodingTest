#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <random>
#include <set>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, ans = 0;
	cin >> n;
    string s;
	cin >> s;
    for (int i = 1; i < n; i++)
    {
        int arr[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
            arr[s[i] - 'A']++;

		string t;
        cin >> t;

        int diff = abs((int)s.size() - (int)t.size());
        if(diff > 1)
			continue; 
        else if (diff == 1)
        {
            for (int i = 0; i < t.size(); i++)
                arr[t[i] - 'A']--;
            int cnt = 0;
            for (int i = 0; i < 26; i++)
                cnt += abs(arr[i]);
            if (cnt <= 1)
                ans++;
        }
        else
        {
            for (int i = 0; i < t.size(); i++)
				if (arr[t[i] - 'A'] > 0)
                    arr[t[i] - 'A']--;
            int cnt = 0;
            for (int i = 0; i < 26; i++)
				cnt += arr[i];
            if (cnt <= 1)
				ans++;
        }
	}

	cout << ans << "\n";

    return 0;
}