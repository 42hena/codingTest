#include <bits/stdc++.h>

using namespace std;

struct Data
{
    string origin;
    string b;
    int number;
    Data (string origin, string b, int number) : origin(origin), b(b), number(number){}
    bool operator<(const Data& copy) const{
        if (this->b != copy.b)
            return this->b < copy.b;
        // if (this->number != copy.number)
        else
            return this->number < copy.number;
        // return 0;
    }
};

/*
bool cmp(vector<Data> v1, vector<Data> v2)
{
    for (int i =0; i < v1.size(); i++) {
    }
    return 0;
}*/

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int size = files.size();
    vector<Data> v;
    for (int i = 0 ; i < size ; ++i)
    {
        string origin = files[i];
        int j = 0;
        string tmp = "";
        for (j = 0 ; j < files[i].size() ; ++j){
            
            if (files[i][j] >= '0' && files[i][j] <= '9')
                break;
            if (files[i][j] >= 'A' && files[i][j] <='Z'){
                files[i][j] += 32;
            }
            tmp += files[i][j];
        }
        int sum = 0;
        for (; j < files[i].size() ; ++j){
            if (files[i][j] >= '0' && files[i][j] <= '9')
                sum = sum * 10 + files[i][j] - '0';
            else
                break;
        }
        v.push_back({origin, tmp , sum});
            
    }
    stable_sort(v.begin(), v.end());
    // file 소문자 처리
    
    // for (auto i : files)
    //     cout << i.origin << '\n';
    for (auto i : v)
    {
        answer.push_back(i.origin);
    }
    return answer;
}