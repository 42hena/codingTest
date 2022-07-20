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
    sort(boxes.begin(), boxes.end());
    
    if (crains[0] < boxes[boxes.size() - 1])
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
                int index = upper_bound(boxes.begin(), boxes.end(), crains[i]) - boxes.begin();
                // cout << i << ' ' << crains[i] << ' ' << index << '\n';
                if (index - 1 < 0)
                    continue;
                // cout << "now value: " << *(boxes.begin() + index - 1) << '\n';
                
                int delValue = *(boxes.begin() + index - 1);
                if (crains[i] < delValue)
                    continue;
                else
                    boxes.erase(boxes.begin() + index - 1);
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