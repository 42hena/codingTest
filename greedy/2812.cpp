#include <iostream>
#include <vector>
using namespace std;

vector<int> s;
int main()
{
    int n, k;
    cin >> n >> k;
    string number;

    cin >> number;
    for (int i = 0 ; i < n ; ++i)
    {
        int value = number[i] - '0';
        
        if (s.empty())
            s.push_back(value);
        else
        {
            int topValue;
            while (!s.empty() && (topValue = s.back()) < value && k > 0)
            {
                s.pop_back();
                k--;
            }
            s.push_back(value);
        }
    }
    while (k--)
    {
        s.pop_back();
    }
    int totalSize = s.size();
    for (int i = 0 ; i < s.size()  ; ++i)
        cout << s[i];
}