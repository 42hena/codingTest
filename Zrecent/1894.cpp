#include <iostream>
#include <vector>
using namespace std;
int arr[100000];
vector<char> op;
vector<int> v;
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &arr[i]);

    int push_value = 1;
    for (int i = 0 ; i < n ; ++i)
    {
        // push
        while (push_value <= arr[i])
        {
            v.push_back(push_value);
            op.push_back('+');
            ++push_value;
        }

        if (v.back() == arr[i])
        {
            op.push_back('-');
            v.pop_back();
        }
    }
    if(v.empty())
    {
        for (int i = 0; i < op.size() ; ++i)
            printf("%c\n", op[i]);
    }
    else
        printf("NO\n");
        
}