#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        stack<char> st;
        for(int j = i; j < i + s.length(); j++)
        {
            if(st.empty())
            {
                st.push(s[j % s.length()]);
            }
            else
            {
                if(st.top() == '(' && s[j % s.length()] == ')') st.pop();
                else if(st.top() == '[' && s[j % s.length()] == ']') st.pop();
                else if(st.top() == '{' && s[j % s.length()] == '}') st.pop();
                else  st.push(s[j % s.length()]);
            }          
        }
        
        
        if(st.empty()) answer++;
    }
    
    
    
    return answer;
}