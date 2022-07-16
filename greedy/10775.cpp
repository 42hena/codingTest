#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
int gates[MAX];

// [g : 게이트의 수]
// [p : 비행기의 수]
int g, p;

// find
int findParent(int x)
{
    if (x == gates[x])
        return x;
    else
        return gates[x] = findParent(gates[x]);
}

void setParent(int gate, int value)
{
    gates[gate] = value;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> g >> p;
    int airplane;

    for (int i = 1 ; i < g + 1 ; ++i)
        gates[i] = i;
    int cnt = 0;
    for (int i = 0 ; i < p ; ++i)
    {
        cin >> airplane;
        bool flag = false;
        int ret = findParent(airplane);
        //부모 값을 찾음
        if (ret)
        {
            // union
            gates[ret] = findParent(ret - 1);
            cnt++;
        }
        // 0이라면 할게 없음
        else
            break;
    }
    cout << cnt;   
}