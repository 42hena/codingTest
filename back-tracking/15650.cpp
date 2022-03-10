#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int arr[8];
vector<int> tmp;
void recursive(int index, int m, int n)
{
    if (tmp.size() == m)
    {
        for (int i = 0 ; i < m ; i++)
            cout << tmp[i] << ' ';
        cout << '\n';
    }
    for (int i = index ; i < n ; i++){
        tmp.push_back(arr[i]);
        recursive(i, m, n);
        tmp.pop_back();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
        arr[i] = i + 1;
    
    recursive(0, m, n);
}