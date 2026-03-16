#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(); // 딱 한 번만 버퍼를 비웁니다.

    set<char> st; // 사용된 단축키 저장 (대문자로 통일)

    while (n--) {
        string s;
        getline(cin, s);

        // 1. 단어별 첫 글자 확인
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);

        bool found = false;
        int targetWordIdx = -1;

        for (int i = 0; i < words.size(); i++) {
            char firstChar = toupper(words[i][0]);
            if (st.find(firstChar) == st.end()) {
                st.insert(firstChar);
                targetWordIdx = i;
                found = true;
                break;
            }
        }

        // 1단계 성공 시 출력
        if (found) {
            for (int i = 0; i < words.size(); i++) {
                if (i == targetWordIdx) {
                    cout << "[" << words[i][0] << "]" << words[i].substr(1);
                } else {
                    cout << words[i];
                }
                if (i != words.size() - 1) cout << " ";
            }
            cout << "\n";
            continue;
        }

        // 2. 1단계 실패 시 모든 글자 순회 (공백 제외)
        int targetCharIdx = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            char curChar = toupper(s[i]);
            if (st.find(curChar) == st.end()) {
                st.insert(curChar);
                targetCharIdx = i;
                found = true;
                break;
            }
        }

        // 결과 출력
        if (found) {
            for (int i = 0; i < s.size(); i++) {
                if (i == targetCharIdx) cout << "[" << s[i] << "]";
                else cout << s[i];
            }
        } else {
            // 단축키를 만들 수 없는 경우 그대로 출력
            cout << s;
        }
        cout << "\n";
    }

    return 0;
}