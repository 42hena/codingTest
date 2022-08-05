#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> rusia(n);
        vector<int> korea(n);
        for (int i = 0; i < n; ++i)
            cin >> rusia[i];
        for (int i = 0; i < n; ++i)
            cin >> korea[i];
        multiset<int, greater<int>> ru(rusia.begin(), rusia.end());
        multiset<int> ko(korea.begin(), korea.end());

        int cnt = 0;
        for (multiset<int, greater<int>>::iterator it = ru.begin(); it != ru.end(); ++it)
        {
            multiset<int, greater<int>>::iterator tmp = ko.lower_bound(*it);
            // cout << "tmp: " << *tmp << '\n';
            if (tmp == ko.end())
            {
                // cout << "start : " << *ko.begin() << '\n';
                ko.erase(ko.begin());
            }
            else
            {
                ko.erase(ko.find(*tmp));
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}