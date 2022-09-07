#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int ans = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        // input
        int x, h;
        cin >> x >> h;

        // 개수가 있을 경우
        if (v.size() > 0)
        {
            int prev = v.back();
            // prev < now
            if (prev < h)
                v.push_back(h);
            else 
            {
                while (!v.empty())
                {
                    prev = v.back();
                    if (prev > h)
                    {
                        ans++;
                        v.pop_back();
                    }
                    else if (prev == h)
                    {
                        v.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                v.push_back(h);
            }
        }
        else
        {
            v.push_back(h);
        }
    }
    while (!v.empty())
    {
        if (v.back() != 0)
            ans++;
        v.pop_back();
    }
    cout << ans;
}