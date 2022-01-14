// 핸드폰 번호 가리기
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int size = phone_number.size();
    string str = phone_number.substr(size - 4, 4);
    string tmp = "";
    for (int i = 0 ; i < size - 4 ; ++i)
        tmp += "*";
    string answer = tmp + str;
    return answer;
}