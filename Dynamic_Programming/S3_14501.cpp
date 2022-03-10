#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 16

int N;
int Ti[MAX]={0,};
int Pi[MAX]={0,};
int res[MAX]={0,};

struct Data
{
    int day;
    int money;
};

int main() {
	cin >> N;
    vector<Data> v(N);
	for (int i=0; i<N; i++){
		cin >> v[i].day >> v[i].money;
	}
	int deadLine;
	for (int i = N - 1; i >= 0; i--){
		deadLine = i + v[i].day;
		if (deadLine > N)
			res[i] = res[i+1];
		else {
			res[i] = max(res[i+1], res[deadLine] + v[i].money);
		}
        for (int j=0; j<=N; j++)
            cout << res[j] << ' ';
        cout << "\n";
	}
	cout << res[0] << endl;
	return 0;
}