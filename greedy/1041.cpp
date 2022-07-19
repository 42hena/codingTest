#include <bits/stdc++.h>
using namespace std;

// [n : 주사위 면]
long long n;
int main(void)
{
    cin >> n;
    vector<int> dice(6);
    vector<int> one;
    for (int i = 0 ; i < 6 ; ++i)
    {
        cin >> dice[i];
        one.push_back(dice[i]);
    }
    
    vector<int> two;
    two.push_back(dice[0] + dice[1]);
    two.push_back(dice[0] + dice[2]);
    two.push_back(dice[0] + dice[3]);
    two.push_back(dice[0] + dice[4]);

    two.push_back(dice[1] + dice[2]);
    two.push_back(dice[1] + dice[3]);
    two.push_back(dice[1] + dice[5]);

    two.push_back(dice[2] + dice[4]);
    two.push_back(dice[2] + dice[5]);

    two.push_back(dice[3] + dice[4]);
    two.push_back(dice[3] + dice[5]);

    two.push_back(dice[4] + dice[5]);

    vector<int> three;
    three.push_back(dice[0] + dice[1] + dice[2]);
    three.push_back(dice[0] + dice[1] + dice[3]);
    three.push_back(dice[0] + dice[2] + dice[4]);
    three.push_back(dice[0] + dice[3] + dice[4]);

    three.push_back(dice[1] + dice[2] + dice[5]);
    three.push_back(dice[1] + dice[3] + dice[5]);
    three.push_back(dice[2] + dice[4] + dice[5]);
    three.push_back(dice[3] + dice[4] + dice[5]);
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    sort(three.begin(), three.end());
    long long total = 0;
    if (n == 1)
    {
        for (int i = 0 ; i < 6 ; ++i)
            total += one;
        total -= one[5];
    }
    else
    {
        
        //3개
        int threeDice = three[0];
        total += threeDice * 4;

        int twoDice = two[0];
        total += twoDice * (4 * (n - 2) + 4 * (n - 1));

        int oneDice = one[0];
        total +=  oneDice * ((n - 2) * (n - 2) + (n - 2) * (n - 1) * 4);

    }
    cout << total;
}