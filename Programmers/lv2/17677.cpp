#include <bits/stdc++.h>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int size1 = str1.size();
    int size2 = str2.size();
    map<string, int> A;
    map<string, int> B;
    set<string> s;
    for (int i = 0 ; i < size1 - 1 ; ++i)
    {
        string tmp;
        if (((str1[i] >='A' && str1[i] <='Z') || (str1[i] >='a' && str1[i] <='z')) && ((str1[i + 1] >='A' && str1[i + 1] <='Z') || (str1[i + 1] >='a' && str1[i + 1] <='z'))){
            if (str1[i] >='A' && str1[i] <='Z')
                tmp += (str1[i] + 32);
            else
                tmp += str1[i];
            if (str1[i + 1] >='A' && str1[i + 1] <='Z')
                tmp += (str1[i + 1] + 32);
            else
                tmp += str1[i + 1];
            s.insert(tmp);
            if (A.find(tmp) == A.end())
                A[tmp] = 1;
            else
                A[tmp]+=1;
        }
    }
    
    
    
    for (int i = 0 ; i < size2 - 1 ; ++i)
    {
        string tmp;
        if (((str2[i] >='A' && str2[i] <='Z') || (str2[i] >='a' && str2[i] <='z')) && ((str2[i + 1] >='A' && str2[i + 1] <='Z') || (str2[i + 1] >='a' && str2[i + 1] <='z'))){
            if (str2[i] >='A' && str2[i] <='Z')
                tmp += (str2[i] + 32);
            else
                tmp += str2[i];
            if (str2[i + 1] >='A' && str2[i + 1] <='Z')
                tmp += (str2[i + 1] + 32);
            else
                tmp += str2[i + 1];
            s.insert(tmp);
            if (B.find(tmp) == B.end())
                B[tmp] = 1;
            else
                B[tmp]+=1;
        }
    }

    double minV = 0;
    double maxV = 0;
    for (auto a : s)
    {
        int aret = 0;
        int bret = 0;
        auto value = A.find(a);
        if ((value) != A.end())
            aret = value->second;
        value = B.find(a);
        if (value != B.end())
            bret = value->second;
        minV += min(aret, bret);
        maxV += max(aret, bret);
    }
    if (minV == 0 && maxV == 0)
        answer = 65536;
    else
        answer = minV / maxV * 65536;
    return answer;
}