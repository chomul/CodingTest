#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long n) {

    if (n <= 1) return false;
    
    for (long long i = 2; i <= sqrt(n); i++)
        if (n%i == 0) return false;        
    
    return true;
}

string changeNumber(int n, int k)
{
    string answer = "";
    while (n >= k)
    {
        answer = to_string(n % k) + answer;
        n = n / k;
    }
    answer = to_string(n) + answer;
    return answer;
}

int solution(int n, int k) {
    int answer = 0;

    string temp = changeNumber(n, k);

    long long num = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '0')
        {
            if (isPrime(num)) answer++;
            num = 0;
            continue;
        }
        else
        {
            num = num * 10 + temp[i] - '0';
        }
    }
    if (num > 0 && isPrime(num)) answer++;
    return answer;
}