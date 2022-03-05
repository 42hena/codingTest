#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<char> oper;
int plusCount, minusCount, multipleCount, divideCount;
int total;
bool visited[11];
int minValue = 2147483647;
int maxValue = -2147483648;
void recursive(int count, vector<char> &operArray)
{
    if (count  == n - 1)
    {
        int sum = v[0];
        for (int i = 0 ; i < n - 1 ; ++i)
        {
            if (operArray[i] == '+')
                sum += v[i + 1];
            
            if (operArray[i] == '-')
                sum -= v[i + 1];
            
            if (operArray[i] == '*')
                sum *= v[i + 1];
            
            if (operArray[i] == '/')
                sum /= v[i + 1];
        }
        minValue = min(sum, minValue);
        maxValue = max(sum, maxValue);
    }
    for (int i = 0 ; i < n - 1 ; ++i)
    {
        if (!visited[i])
        {
            operArray.push_back(oper[i]);
            visited[i] = true;
            recursive(count + 1, operArray);
            visited[i] = false;
            operArray.pop_back();
        }
    }
}

int main(void)
{
    cin >> n;
    v.resize(n);
    // oper.resize(n - 1);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    cin >> plusCount >> minusCount >> multipleCount >> divideCount;
    for (int i = 0 ; i < plusCount ; ++i)
        oper.push_back('+');
    for (int i = 0 ; i < minusCount ; ++i)
        oper.push_back('-');
    for (int i = 0 ; i < multipleCount ; ++i)
        oper.push_back('*');
    for (int i = 0 ; i < divideCount ; ++i)
        oper.push_back('/');
    total = plusCount + minusCount + multipleCount + divideCount;
    vector<char> operArray;
    recursive(0, operArray);
    cout << maxValue << '\n' << minValue;
}