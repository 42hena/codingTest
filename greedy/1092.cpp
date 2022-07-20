#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> crains(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> crains[i];
    }

    int m;
    cin >> m;
    vector<int> boxes(m);
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> boxes[i];
    }
    
    sort(crains.begin(), crains.end(), greater<>());
    sort(boxes.begin(), boxes.end(), greater<>());
    
    if (crains[0] < boxes[0])
    {
        cout << -1;
        exit(0);
    }
    int time = 0;
    while (true)
    {
        time++;
        bool flag = false;
        for (int i = 0 ; i < crains.size() ; ++i)
        {
            if (boxes.size())
            {
                for (int j = 0 ; j < boxes.size() ; ++j)
                {
                    if (crains[i] >= boxes[j])
                    {
                        boxes.erase(boxes.begin() + j);
                        break ;
                    }
                }
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (!boxes.size() || flag)
            break;
        
    }
    cout << time;
}