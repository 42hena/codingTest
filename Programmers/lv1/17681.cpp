#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0 ; i < n ; ++i)
    {
        string tmp = "";
        int value = arr1[i] | arr2[i];
        int k = 1 << (n - 1);
        for (int j = 0 ; j < n ; ++j)
        {
            if (value & k)
                tmp += "#";
            else
                tmp += " ";
            k = k >> 1;
        }
        answer.push_back(tmp);
    }
    return answer;
}